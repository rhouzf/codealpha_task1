const express = require('express');
const fs = require('fs');
const yaml = require('js-yaml');
const app = express();
const cors = require('cors');
app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
// Ajoutez cette route pour gérer l'accès à la racine de votre application
//app.get('/', (req, res) => {
    // Envoyez le fichier HTML en réponse
  //  res.sendFile(__dirname + '/index.html');
//});
app.use(express.static('public'))



// Votre route POST actuelle pour gérer la soumission du formulaire
app.post('/api/submit', (req, res) => {
    const data = req.body;

    console.log('Données reçues :', data);

    // Utilisez yaml.dump au lieu de yaml.safeDump
    fs.writeFile('ansible.yml', yaml.dump(data), (err) => {
        if (err) {
            
            console.error(err);
            res.status(500).send('Erreur lors de l\'écriture du fichier');
        } else {
             console.log('Données stockées avec succès');
             res.redirect('/index2.html');
            // res.status(200).send('succes ');
        }
    });
});

app.listen(3000, () => console.log('Serveur en écoute sur le port 3000'));
