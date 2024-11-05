#include <iostream>
#include <fstream>
#include "Utilisateur.h"
#include "Image.h"

using namespace std;

int main()
{
    // Création d'un nouvel utilisateur
    Utilisateur utilisateur(1, "Dupont", "jean.dupont@example.com", "monMotDePasse");

    // Affichage des informations de l'utilisateur
    //utilisateur.afficherInformations();

    // Sauvegarder l'utilisateur dans un fichier
    /*ofstream fichier("utilisateurs.txt", ios::app);
    if (fichier.is_open()) {
        utilisateur.sauvegarder(fichier);
        fichier.close();
        cout << "Utilisateur sauvegardé dans utilisateurs.txt" << endl;
    } else {
        cout << "Erreur lors de l'ouverture du fichier !" << endl;
    }*/


    /*cout << "\nListe des utilisateurs chargés:" << endl;
    for (const auto& u : utilisateurs) {
        u.afficherInformations();
    }*/

    //CONNEXION
    /*string name;
    string motdepasse;
    // Charger les utilisateurs depuis le fichier
    vector<Utilisateur> utilisateurs = Utilisateur::charger("utilisateurs.txt");


    cout << "Entrez votre nom d'utilisateur: ";
    cin >> name;
    cout << "Entrez votre mot de passe: ";
    cin >> motdepasse;

    bool connexionReussie = false;
    for (const auto& utilisateur : utilisateurs) {
        if (utilisateur.seConnecter(name, motdepasse)) {
            connexionReussie = true;
            std::cout << "Connexion reussie ! Bienvenue, " << utilisateur.get_nomUser() << " !" << std::endl;
            break;
        }
    }

    if (!connexionReussie) {
        std::cout << "Echec de la connexion. Verifiez votre email et votre mot de passe." << std::endl;
    }*/

    //CREATION et AFFICHAGE D IMAGE
    Image image1("photo.jpg");
    image1.afficher();

    //TELECHARGEMENT D IMAGE
    utilisateur.telechargerImage("image1.jpg");
    utilisateur.telechargerImage("photo.jpg");

    //AFFICHAGE DE LA GALERIE
    utilisateur.afficherGalerie();


    return 0;
}
