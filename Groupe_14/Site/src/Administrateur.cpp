#include "Administrateur.h"
#include "Utilisateur.h"
#include <iostream>
#include "Image.h"
#include <sstream>
#include "json.hpp"

using json = nlohmann::json;

Administrateur::Administrateur(const std::string& nom)
{
    nomAdmin = nom;
}


void Administrateur::ajouterCategorie(const std::string& nomCategorie, const std::string& descriptionCategorie, const std::string& nomFichier)
{
    //oui j'aime beaucoup les fichiers json

    std::ifstream fichierLecture(nomFichier);
    json categories;

    if (fichierLecture.is_open()) {
        fichierLecture >> categories;  // Charger les catégories existantes
        fichierLecture.close();
    }

    // Ajoute la nouvelle catégorie
    json nouvelleCategorie;
    nouvelleCategorie["nom"] = nomCategorie;
    nouvelleCategorie["description"] = descriptionCategorie;

    categories.push_back(nouvelleCategorie);

    // Sauvegarder les modifications dans le fichier
    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open()) {
        fichierEcriture << categories.dump(4);  // Réécrire tout le fichier JSON avec un format lisible
        fichierEcriture.close();
    }
}

void Administrateur::afficherCategories(const std::string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    json categories;

    if (fichierLecture.is_open()) {
        fichierLecture >> categories;  // Charger les catégories existantes
        fichierLecture.close();
    }

    std::cout << "Catégories disponibles :\n";
    for (const auto& categorie : categories) {
        std::cout << "Nom: " << categorie["nom"] << "\n";
        std::cout << "Description: " << categorie["description"] << "\n\n";
    }
}

void Administrateur::supprimerCategorie(const std::string& nomCategorie, const std::string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    json categories;

    if (fichierLecture.is_open()) {
        fichierLecture >> categories;
        fichierLecture.close();
    }


    categories.erase(std::remove_if(categories.begin(), categories.end(),
        [&nomCategorie](const json& categorie) {
            return categorie["nom"] == nomCategorie;
        }), categories.end());


    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open()) {
        fichierEcriture << categories.dump(4);
        fichierEcriture.close();
    }
}

void Administrateur::filtrerCategorie(const std::string& categorie, const std::string& nomFichier)
{
        std::ifstream fichierLecture(nomFichier);
        json images; //on va retourner l'objet json avec les images qui correspondent

        if (fichierLecture.is_open()) {
            fichierLecture >> images;
            fichierLecture.close();
        }

        // Filtrer les images qui appartiennent à la catégorie qu'on a mis en parametre
        std::vector<json> imagesFiltrees;
        for (const auto& image : images) {
            if (image["categorie"] == categorie) {
                imagesFiltrees.push_back(image);
            }
        }

        // Afficher les images filtrées
        if (!imagesFiltrees.empty()) {
            std::cout << "Images dans la categorie '" << categorie << "':" << std::endl;
            for (const auto& image : imagesFiltrees) {
                std::cout << "Nom: " << image["nomImage"] << std::endl;
                std::cout << "Description: " << image["descriptionImage"] << std::endl;
                std::cout << "Utilisateur: " << image["nomUtilisateur"] << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        } else {
            std::cout << "Aucune image trouvée dans la categorie '" << categorie << "'." << std::endl;
        }
}

void Administrateur::ajouterUtilisateur(int id, const std::string& nomUser, const std::string& mail, const std::string& motdepasse, const std::string& nomFichier) {
        // Créer un nouvel utilisateur avec les informations fournies
        Utilisateur nouvelUtilisateur(id, nomUser, mail, motdepasse, {}, {});

        // Convertir l'utilisateur en json
        json utilisateurJson = nouvelUtilisateur.to_json();


        std::ifstream fichierLecture(nomFichier);
        json data;

        if (fichierLecture.is_open()) {
            fichierLecture >> data;
            fichierLecture.close();
        }

        data.push_back(utilisateurJson);


        std::ofstream fichierEcriture(nomFichier);
        if (fichierEcriture.is_open()) {
            fichierEcriture << data.dump(4);
            fichierEcriture.close();
        }

        std::cout << "Utilisateur ajoute avec succes!" << std::endl;
}

void Administrateur::supprimerUtilisateur(const std::string& nomUser, const std::string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    json data;

    if (fichierLecture.is_open())
    {
        fichierLecture >> data;
        fichierLecture.close();
    }

    // Trouver l'utilisateur à supprimer par son nom
    auto it = std::find_if(data.begin(), data.end(), [nomUser](const json& utilisateur) {
        return utilisateur["nomUser"] == nomUser;
    });

    if (it != data.end()) {
        data.erase(it);
        std::cout << "Utilisateur supprimé avec succès." << std::endl;
    } else {
        std::cerr << "Utilisateur " << nomUser << " non trouvé." << std::endl;
        return;
    }


    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open())
    {
        fichierEcriture << data.dump(4);
        fichierEcriture.close();
    }
}

void Administrateur::approuverImageSoumise(const string& nomImage, const std::string& nomFichierAttente, const std::string& nomFichierFinal){
    std::ifstream fichierAttenteLecture(nomFichierAttente); //ici on charge les images qui sont en attente de validation
    json dataEnAttente;

    if (fichierAttenteLecture.is_open())
    {
        fichierAttenteLecture >> dataEnAttente;  // Charger les images en attente
        fichierAttenteLecture.close();
    }
    auto it = std::find_if(dataEnAttente.begin(), dataEnAttente.end(), [nomImage](const json& image) {
        return image["nomImage"] == nomImage;
    });

    if (it != dataEnAttente.end()) {
        // L'image a été trouvée, on va changer maintenant le statut d'approbation
        it->at("estApprouvee") = true;

    //On envoie l'image dans notre fichier final
        std::ifstream fichierFinalLecture(nomFichierFinal);
        json dataFinal;

        if (fichierFinalLecture.is_open()) {
            fichierFinalLecture >> dataFinal;
            fichierFinalLecture.close();
        }

        // Ajouter l'image approuvée au fichier final
        dataFinal.push_back(*it);

        std::ofstream fichierFinalEcriture(nomFichierFinal);
        if (fichierFinalEcriture.is_open()) {
            fichierFinalEcriture << dataFinal.dump(4);  // Réécrire tout le fichier JSON avec l'image ajoutée
            fichierFinalEcriture.close();
        }

        dataEnAttente.erase(it); //on enleve des images à valider

         std::ofstream fichierAttenteEcriture(nomFichierAttente);
        if (fichierAttenteEcriture.is_open()) {
            fichierAttenteEcriture << dataEnAttente.dump(4);  // Réécrire tout le fichier JSON sans l'image approuvée
            fichierAttenteEcriture.close();
        }

        std::cout << "L'image a ete approuvee et transferee dans le fichier final." << std::endl;
    } else {
        std::cerr << "L'image " << nomImage << " n a pas ete trouvee." << std::endl;
    }

}





