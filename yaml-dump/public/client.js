document.addEventListener('DOMContentLoaded', function () {
    // Récupérer le formulaire
    let form = document.getElementById('monFormulaire');

    // Ajouter un écouteur d'événements pour la soumission du formulaire
    form.addEventListener('submit', function (event) {

        // Empêcher la soumission normale du formulaire
        event.preventDefault();

        // Récupérer les valeurs des champs de formulaire
        let instanceType = document.getElementById('instance_type').value;
        let imageId = document.getElementById('image_id').value;
        let region = document.getElementById('region').value;

        // Afficher les valeurs des champs dans la console
        console.log('instanceType:', instanceType);
        console.log('imageId:', imageId);
        console.log('region:', region);

        // Envoyer une requête AJAX avec les données du formulaire
        fetch('http://localhost:3000/api/submit', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                instanceType: instanceType,
                imageId: imageId,
                region: region
            })
        })
        .then(response => {
            console.log("erreur")
            // Rediriger vers /index2.html après la soumission réussie du formulaire
            if (response.ok) {
                window.location.replace('/index2.html');
            } else {
                console.error('La requête a échoué:', response.statusText);
            }
        })
        .catch(error => {
            console.error('Erreur lors de la requête:', error);
        });

    });
});