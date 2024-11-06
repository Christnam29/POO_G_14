#include <iostream>
#include <fstream>
#include "Utilisateur.h"
#include "Image.h"

using namespace std;

int main()
{
    // Création d'un nouvel utilisateur
    Utilisateur utilisateur(1, "Dupont", "jean.dupont@example.com", "monMotDePasse");
    Utilisateur user2(2, "Jean", "jean@yahoo.fr", "1234");
    // Affichage des informations de l'utilisateur
    //utilisateur.afficherInformations();

    // Sauvegarder l'utilisateur dans un fichier
    ofstream fichier("utilisateurs.txt", ios::app);
    if (fichier.is_open()) {
        user2.sauvegarder(fichier);
        fichier.close();
        cout << "Utilisateur sauvegarde dans utilisateurs.txt" << endl;
    } else {
        cout << "Erreur lors de l'ouverture du fichier !" << endl;
    }


    /*cout << "\nListe des utilisateurs chargés:" << endl;
    for (const auto& u : utilisateurs) {
        u.afficherInformations();
    }*/

    //CONNEXION
    string name;
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
            cout << "Connexion reussie ! Bienvenue, " << utilisateur.get_nomUser() << " !" << endl;
            break;
        }
    }

    if (!connexionReussie) {
        std::cout << "Echec de la connexion. Verifiez votre email et votre mot de passe." << std::endl;
    }

    //CREATION et AFFICHAGE D IMAGE
    /*Image image1("photo.jpg");
    image1.afficher();*/

    //TELECHARGEMENT D IMAGE
    /*utilisateur.telechargerImage("image1.jpg");
    utilisateur.telechargerImage("photo.jpg");
    utilisateur.supprimerImageDeGalerie("image1.jpg");
    utilisateur.liker("image1.jpg");
    utilisateur.afficherGalerie();
    utilisateur.afficherFavoris();*/

    //AFFICHAGE DE LA GALERIE
    /*utilisateur.afficherGalerie();*/

    //AJOUT DE FAVORIS
    /*utilisateur.liker("image1.jpg");
    utilisateur.afficherFavoris();*/

    int choix;
    int sousChoix;
    string nomImage;


    while (true) {
        cout << "\n--- Menu de l'application d'images ---\n";
        cout << "1. Afficher la galerie\n";
        cout << "2. Télécharger une image\n";
        cout << "3. Ajouter une image aux favoris\n";
        cout << "4. Supprimer une image\n";
        cout << "5. Quitter\n";
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                utilisateur.afficherGalerie();
                break;

            case 2:
                cout << "Quelle image voulez-vous telecharger?: ";
                cin >> nomImage;
                utilisateur.telechargerImage(nomImage);
                break;

            case 3:
                cout << "Quelle image voulez-vous liker?: ";
                cin >> nomImage;
                utilisateur.liker(nomImage);
                break;

            case 4:
                cout << "D'ou voulez-vous supprimer des images?: \n";
                cout << "1. De la galerie\n";
                cout << "2. Des favoris\n";
                cin >> sousChoix;

                switch(sousChoix){
                case 1:
                    cout << "Quelle image voulez-vous supprimer?: ";
                    cin >> nomImage;
                    utilisateur.supprimerImageDeGalerie(nomImage);
                    break;

                case 2:
                    cout << "Quelle image voulez-vous supprimer?: ";
                    cin >> nomImage;
                    utilisateur.supprimerImageDeFavoris(nomImage);
                    break;
                }

            case 5:
                utilisateur.quitterApp();
                return 0;

            default:
                cout << "Choix invalide. Veuillez reessayer.\n";
        }
    }

    return 0;
}
