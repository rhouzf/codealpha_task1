<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Récupérer les valeurs du formulaire
    $instance_type = htmlspecialchars($_POST['instance_type']);
    $image_id = htmlspecialchars($_POST['image_id']);
    $region = htmlspecialchars($_POST['region']);
    $ansible_user = htmlspecialchars($_POST['ansible_user']);
    $num_pods = intval($_POST['num_pods']);
    $num_containers = intval($_POST['num_containers']);
    $container_image = htmlspecialchars($_POST['container_image']);
    $request_memory = htmlspecialchars($_POST['request_memory']);
    $request_cpu = htmlspecialchars($_POST['request_cpu']);

    // Lire et mettre à jour le fichier Ansible
    $file_path = 'newtask.yaml';
    if (!file_exists($file_path)) {
        echo "Erreur: le fichier Ansible n'existe pas.";
        exit;
    }

    $file_contents = file_get_contents($file_path);
    if ($file_contents === false) {
        echo "Erreur lors de la lecture du fichier Ansible.";
        exit;
    }

    // Remplacer les valeurs dans le contenu du fichier
    $patterns = [
        '/instance_type: .*/',
        '/image_id: .*/',
        '/region: .*/',
        '/ansible_user: .*/',
        '/num_pods: .*/',
        '/num_containers: .*/',
        '/container_image: .*/',
        '/request_memory: .*/',
        '/request_cpu: .*/'
    ];

    $replacements = [
        "instance_type: $instance_type",
        "image_id: $image_id",
        "region: $region",
        "ansible_user: $ansible_user",
        "num_pods: $num_pods",
        "num_containers: $num_containers",
        "container_image: $container_image",
        "request_memory: $request_memory",
        "request_cpu: $request_cpu"
    ];

    $file_contents = preg_replace($patterns, $replacements, $file_contents);

    // Écrire le contenu modifié dans le fichier
    $result = file_put_contents($file_path, $file_contents);
    if ($result === false) {
        echo "Erreur lors de l'écriture du fichier Ansible.";
        exit;
    } else {
        echo "Données enregistrées dans le fichier Ansible.<br>";
    }

    // Exécuter le fichier Ansible
    $command = escapeshellcmd("ansible-playbook $file_path");
    $output = shell_exec($command);
    if ($output === null) {
        echo "Erreur lors de l'exécution du fichier Ansible.";
    } else {
        echo "Exécution du fichier Ansible réussie.<br>";
        echo "<pre>$output</pre>";
    }
   
    // Charger le contenu du fichier data.json
    $ip_instance = file_get_contents('data.json');

    // Vérifier si l'adresse IP a bien été récupérée
    if ($ip_instance !== false && filter_var($ip_instance, FILTER_VALIDATE_IP)) {
        echo "L'adresse IP de l'instance est : " . $ip_instance;
    } else {
        echo "Adresse IP non trouvée ou invalide dans le fichier JSON.";
    }
    // Afficher le lien pour accéder au terminal
    echo "Accéder au terminal avec ce lien: <a href=\"http://$ip_instance:8080\">Terminal</a>";



}
?>