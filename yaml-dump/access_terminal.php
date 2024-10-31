<?php
// Récupérer l'adresse IP de l'instance EC2 à partir du fichier JSON
$json_content = file_get_contents('data.json');
$instance_data = json_decode($json_content, true);
$ip_instance = $instance_data['instances'][0]['network_interfaces'][0]['association']['public_ip'];

// Exécuter la commande ttyd sur l'instance EC2
$ttyd_command = 'ttyd --writeable -p 8080 tmux';
$ttyd_output = shell_exec($ttyd_command);

// Vérifier la sortie de la commande SSH
if ($ttyd_output === null) {
    echo "Erreur lors de l'exécution de la commande ttyd.";
} else {
    echo "La commande ttyd a été exécutée avec succès.<br>";
}


?>
