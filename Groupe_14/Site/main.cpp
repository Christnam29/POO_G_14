#include <iostream>
#include <fstream>
#include "Utilisateur.h"
#include "Image.h"
#include "Administrateur.h"
#include "json.hpp"



int main()
{
    // Création d'un nouvel utilisateur
    Utilisateur user2(2, "Dupont", "jean.dupont@example.com", "1234", {}, {});
    Utilisateur user1(1, "Jean", "jean@yahoo.fr", "1234", {}, {});
    // Affichage des informations de l'utilisateur
    //utilisateur.afficherInformations();

    //user2.sauvegarder("utilisateurs.json");
    //cout << "Utilisateur sauvegarde dans utilisateurs.json" << endl;

    /*cout << "\nListe des utilisateurs chargés:" << endl;
    for (const auto& u : utilisateurs) {
        u.afficherInformations();
    }*/

    //CONNEXION
    std::string name;
    std::string motdepasse;
    Utilisateur user; //User par défaut

        /*cout << "Entrez votre nom d'utilisateur: ";
        cin >> name;
        cout << "Entrez votre mot de passe: ";
        cin >> motdepasse;

        user.seConnecter(name, motdepasse, "utilisateurs.json");*/


    Image image1(1, "coucher_soleil", "png", "Un coucher de soleil magnifique", "nature", true, false, {"soleil", "nature", "coucher"});
    //user1.liker(image1, "utilisateurs.json");
    //user1.soumettreImage("image_en_attente.json");
    //image1.enregistrerImage("image_en_attente.json");
    //Image image2("le_ciel.png");
    //La méthode seConnecter crée des variables qui stockent les infos de l'utilisateur connecté. Les autres méthodes savent alors quel utilisateur modifier!
    //user.telechargerImage("le_ciel.png", "utilisateurs.json");

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

    /*int choix;
    int sousChoix;
    std::string nomImage;

     while (true) {
         cout << "\n======= Menu de l'application d'images ========\n";
         cout << "1. Afficher les images disponibles\n";
         cout << "2. Telecharger une image\n";
         cout << "3. Afficher les favoris\n";
         cout << "4. Afficher la galerie\n";
         cout << "5. Liker une image\n";
         cout << "6. Gerer ses images\n";
         cout << "7. Quitter\n";
         cout << "Entrez votre choix : ";
         cin >> choix;

         switch (choix) {
             case 1:
                 user.afficherGalerie();
                 break;

             case 2:
                 cout << "Quelle image voulez-vous telecharger?: ";
                 cin >> nomImage;
                 user.telechargerImage(nomImage, "utilisateurs.json");
                 break;

             case 3:
                user.afficherFavoris();
                break;

            case 4:
                user.afficherGalerie();
                break;

             case 5:
                 cout << "Quelle image voulez-vous liker?: ";
                 cin >> nomImage;
                 user.liker(nomImage, "utilisateurs.json");
                 break;

             case 6:
                 cout << "1. Soumettre une image\n";
                 cout << "2. Supprimer des images\n";
                 cout << "Que voulez-vous faire ?: ";
                 cin >> sousChoix;

                 switch (sousChoix){

                    case 1:
                        user.soumettreImage("images_en_attente");
                        break;

                    case 2:
                         cout << "1. De la galerie\n";
                         cout << "2. Des favoris\n";
                         cout << "D'ou voulez-vous supprimer des images?: ";
                         cin >> sousChoix;

                         switch(sousChoix){
                         case 1:
                             cout << "Quelle image voulez-vous supprimer?: ";
                             cin >> nomImage;
                             user.supprimerImageDeGalerie(nomImage, "utilisateurs.json");
                             break;

                         case 2:
                             cout << "Quelle image voulez-vous supprimer?: ";
                             cin >> nomImage;
                             user.supprimerImageDeFavoris(nomImage, "utilisateurs.json");
                             break;

                         default:
                            cout << "Choix invalide. Veuillez reessayer.\n";
                         }
                     default:
                        cout << "Choix invalide. Veuillez reessayer.\n";
                 }
             break;

             case 7:
                 user.quitterApp();
                 return 0;

             default:
                 cout << "Choix invalide. Veuillez reessayer.\n";
                 break;
         }
     }*/
    //Passons à l'administrateur!
     Administrateur admin("admin1");
     //admin.ajouterCategorie("Sexualite", "Les images erotiques", "categories.json");
     //admin.filtrerCategorie("Technologie", "image_en_attente.json");
     //admin.ajouterUtilisateur(5, "Divin", "divinsehlin@gmail.com", "1234", "utilisateurs.json");
    //admin.approuverImageSoumise("coucher_soleil", "image_en_attente.json", "images.json");

//DASHBOARD ADMIN

int choix = 0;
 int id;
string nom, email, motDePasse, categorie, description;


        do {
            cout << "\n======Menu Administrateur=========\n";
            cout << "1. Ajouter un utilisateur\n";
            cout << "2. Supprimer un utilisateur\n";
            cout << "3. Approuver une image\n";
            cout << "4. Créer une categorie d'image\n";
            cout << "5. Supprimer une categorie d'image\n";
            cout << "6. Filtrer les images par categorie\n";
            cout << "7. Filtrer les images par mots cles\n";
            cout << "8. Quitter\n";
            cout << "Choisissez une option : ";
            cin >> choix;

            switch (choix) {
                case 1:
                    cout << "Entrez l'identifiant (id) de l'utilisateur : ";
                    cin >> id;
                    cout << "Entrez le nom de l'utilisateur : ";
                    cin >> nom;
                    cout << "Entrez l'email : ";
                    cin >> email;
                    cout << "Entrez le mot de passe : ";
                    cin >> motDePasse;
                    admin.ajouterUtilisateur(id, nom, email, motDePasse, "utilisateurs.json");
                    break;

                case 2:
                    cout << "Entrez le nom de l'utilisateur : ";
                    cin >> nom;
                    admin.supprimerUtilisateur(nom, "utilisateurs.json");
                    break;

                case 3:
                    json imagesEnAttente;
                    ifstream fichierLecture("image_en_attente.json");
                    if (fichierLecture.is_open()) {
                        fichierLecture >> imagesEnAttente;
                        fichierLecture.close();
                    } else {
                        cout << "Erreur lors de l'ouverture du fichier images_en_attente.json" << endl;
                        continue;
                    }

                    if (imagesEnAttente.empty()) {
                        cout << "Aucune image en attente d'approbation." << endl;
                        continue;
                    }

                    // Afficher les images en attente
                    cout << "Images en attente d'approbation :\n";
                    for (size_t i = 0; i < imagesEnAttente.size(); ++i) {
                        cout << ", Nom: " << imagesEnAttente[i]["nomImage"]
                             << ", Categorie: " << imagesEnAttente[i]["categorie"]
                             << ", Soumise par: " << imagesEnAttente[i]["nomUtilisateur"] << endl;
                    }
                    cout << "Entrez le nom de l'image que vous souhaitez approuver : ";
                    cin >> nom;
                    admin.approuverImageSoumise(nom, "image_en_attente.json", "images.json");
                    break;

                case 4:
                    cout << "Entrez le nom de la nouvelle categorie : ";
                    cin >> categorie;


                    cout << "Decrivez-la : ";
                    cin >> description;
                    admin.ajouterCategorie(categorie, description, "categories.json");
                    cout << "Categorie creee avec succes !" << endl;
                    break;

                case 5:
                    cout << "Entrez le nom de la categorie a supprimer : ";
                    cin >> categorie;
                    admin.supprimerCategorie(categorie, "categorie.json");
                    break;

                case 6:
                    cout << "Entrez le nom de la categorie pour filtrer les images : ";
                    cin >> categorie;
                    admin.filtrerCategorie(categorie, "images.json");
                    break;

                case 7:
                    //filtrerImages();
                    break;
                case 8:
                    cout << "Au revoir administrateur. Vous etes le meilleur!" << endl;
                    break;

                default:
                    cout << "Option invalide, essayez encore." << endl;
                    break;
            }
        } while (choix != 8);

    return 0;
}
