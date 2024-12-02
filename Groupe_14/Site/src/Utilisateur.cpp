#include <iostream>
#include "Utilisateur.h"
#include "Image.h"
#include <sstream>
#include "json.hpp"
using json = nlohmann::json;



Utilisateur::Utilisateur() {
    id = 0;
    nomUser = "Inconnu";
    mail = "email@example.com";
    motdepasse = "default";
    galerie = {};
    favoris = {};
}

Utilisateur::Utilisateur(int identifiant, std::string name, std::string email, std::string mdp, std::vector<Image> glrie, std::vector<Image> fvs){
    id = identifiant;
    nomUser= name;
    mail= email;
    motdepasse= mdp;
    galerie = glrie;
    favoris = fvs;
}

 json Utilisateur::to_json() const {
        return json{
            {"id", id},
            {"nomUser", nomUser},
            {"mail", mail},
            {"motdepasse", motdepasse},
            { "galerie", json::array()},
            { "favoris", json::array()}
        };
}

//Accesseurs
int Utilisateur::get_id() const
{
    return id;
}

std::string Utilisateur::get_nomUser() const
{
    return nomUser;
}

std::string Utilisateur::get_mail() const
{
    return mail;
}

std::string Utilisateur::get_motdepasse() const
{
    return motdepasse;
}

//Mutateurs
void Utilisateur::set_id(int val)
{
    id = val;
}

void Utilisateur::set_nomUser(std::string val)
{
    nomUser = val;
}

void Utilisateur::set_mail(std::string val)
{
    mail = val;
}

void Utilisateur::set_motdepasse(std::string val)
{
    motdepasse = val;
}

//Autres méthodes
// Méthode pour afficher les informations de l'utilisateur
void Utilisateur::afficherInformations() const
{
    std::cout << "ID: " << id << endl;
    std::cout << "Nom: " << nomUser << endl;
    std::cout << "Email: " << mail << endl;
    std::cout << "Password: " << motdepasse << endl; //ligne à mettre en commentaire!!
}

void Utilisateur::sauvegarder(const std::string& nomFichier){
    json data;

    std::ifstream fichierLecture(nomFichier);
    if (fichierLecture.is_open())
    {
        fichierLecture >> data;
        fichierLecture.close();
    }

    json utilisateurJson =
    {
        {"id", id},
        {"nomUser", nomUser},
        {"mail", mail},
        {"motdepasse", motdepasse},
        { "galerie", json::array()},
        { "favoris", json::array()}
    };

    data.push_back(utilisateurJson);


// Sauvegarde dans le fichier
std::ofstream fichier(nomFichier);
if (fichier.is_open())
{
    fichier << data.dump(4);  // Écriture avec une indentation de 4 espaces
    fichier.close();
}
else
{
    std::cerr << "Erreur lors de l'ouverture du fichier pour sauvegarde." << endl;
}
}

vector<Utilisateur> Utilisateur::charger(const string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    std::vector<Utilisateur> utilisateurs;
    json data;

    if (fichier.is_open())
    {
        fichier >> data;  // Chargement des données JSON
        fichier.close();

        // Parcourir chaque utilisateur dans le fichier JSON
        for (const auto& utilisateurJson : data)
        {
                int id = utilisateurJson["id"];
                string name = utilisateurJson["nomUser"];
                string email = utilisateurJson["mail"];
                string mdp = utilisateurJson["motdepasse"];

                // Conversion des galeries en string
            vector<Image> galerie;
            for (const auto& imgJson : utilisateurJson["galerie"])
            {
                int id = imgJson["id"];
                string nomFichier = imgJson["nomImage"];
                string format = imgJson["format"];
                string description = imgJson["descriptionImage"];
                string categorie = imgJson["categorie"];
                bool publique = imgJson["estPublique"];
                bool approuvee = imgJson["estApprouvee"];
                vector<string> motsCles = imgJson["motsCles"];

                galerie.push_back(Image(id, nomFichier, format, description, categorie, publique, approuvee, motsCles));

            }

            // Conversion des favoris
            std::vector<Image> favoris;
            for (const auto& imgJson : utilisateurJson["favoris"])
            {
                int id = imgJson["id"];
                string nomFichier = imgJson["nomImage"];
                string format = imgJson["format"];
                string description = imgJson["descriptionImage"];
                string categorie = imgJson["categorie"];
                bool publique = imgJson["estPublique"];
                bool approuvee = imgJson["estApprouvee"];
                vector<string> motsCles = imgJson["motsCles"];

                favoris.push_back(Image(id, nomFichier, format, description, categorie, publique, approuvee, motsCles));
            }

            utilisateurs.emplace_back(id, name, email, mdp, galerie, favoris);
        };

    }
    return utilisateurs;
}

bool Utilisateur::seConnecter(const std::string& name, const std::string& mdp, const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return false;
    }


    json data;
    fichier >> data;
    fichier.close();
        for (const auto& utilisateurJson : data) {
            if (utilisateurJson["nomUser"] == name && utilisateurJson["motdepasse"] == mdp) {
                // Authentification réussie, on charge les données
                id = utilisateurJson["id"];
                nomUser = utilisateurJson["nomUser"];
                mail = utilisateurJson["mail"];
                motdepasse = utilisateurJson["motdepasse"];

                // Charger la galerie et les favoris
                galerie.clear();
                favoris.clear();

                for (const auto& image : utilisateurJson["galerie"]) {
                    galerie.emplace_back(Image(image));  // Reconversion en objet Image
                }

                for (const auto& image : utilisateurJson["favoris"]) {
                    favoris.emplace_back(Image(image));
                }

                cout << "Bienvenue " <<nomUser << "!" << endl;
                return true;
            }
        }

        std::cout << "Nom d'utilisateur ou mot de passe incorrect." << std::endl;
        return false;

}


void Utilisateur::telechargerImage(const Image& image, const std::string& nomFichier )
{
    std::ifstream fichierLecture(nomFichier);
    json data;

    if (fichierLecture.is_open())
    {
        fichierLecture >> data;  // Charger les utilisateurs existants
        fichierLecture.close();
    }

    // Trouver l'utilisateur par ID et ajouter l'image à sa galerie
    for (auto& utilisateur : data)
    {
        if (utilisateur["id"] == id)
        {
            utilisateur["galerie"].push_back(image.toJson());
            break;
        }
    }

    // Sauvegarder les modifications
    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open())
    {
        fichierEcriture << data.dump(4);  // Réécrire tout le fichier JSON
        fichierEcriture.close();
    }
}


void Utilisateur::afficherGalerie() const
{
    // Il faut recharger la galerie depuis le fichier JSON à chaque appel
    std::ifstream fichierLecture("utilisateurs.json");
    json data;

    if (fichierLecture.is_open()) {
        fichierLecture >> data;
        fichierLecture.close();
    }

    // Chercher l'utilisateur par son ID et mettre à jour la galerie
    for (const auto& utilisateurJson : data) {
        if (utilisateurJson["id"] == id) {
            // Si la galerie est vide, afficher un message approprié
            if (utilisateurJson["galerie"].empty()) {
                std::cout << "Galerie vide pour " << nomUser << "." << std::endl;
            } else {
                // Sinon, afficher la galerie
                std::cout << "Galerie de " << nomUser << " :" << std::endl;
                for (const auto& image : galerie) {
                    // Chaque image est reconvertie en objet Image et son nom est affiché
                    std::cout << "- " << image.getNomImage() << std::endl;
                }
            }
            break;  // Sortir dès qu'on trouve l'utilisateur
        }
    }
}


void Utilisateur::supprimerImageDeGalerie(const std::string& nomImage, const std::string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    json data;

    if (fichierLecture.is_open())
    {
        fichierLecture >> data;
        fichierLecture.close();
    }

    // Trouver l'utilisateur par ID et supprimer l'image de la galerie
    for (auto& utilisateur : data)
    {
        if (utilisateur["id"] == id)
        {
            auto& galerie = utilisateur["galerie"];
            galerie.erase(std::remove_if(galerie.begin(), galerie.end(),
                                      [nomImage](const json& imageJson) { return imageJson["nomImage"] == nomImage;}
                                      ), galerie.end());
            break;
        }
    }

    // Sauvegarder les modifications
    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open())
    {
        fichierEcriture << data.dump(4);  // Réécrire tout le fichier JSON
        fichierEcriture.close();
    }
}



void Utilisateur::liker(const Image& image, const string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    json data;

    if (fichierLecture.is_open())
    {
        fichierLecture >> data;  // Charger les utilisateurs existants
        fichierLecture.close();
    }

    // Trouver l'utilisateur par ID et ajouter l'image aux favoris
    for (auto& utilisateur : data)
    {
        if (utilisateur["id"] == id)
        {
            utilisateur["favoris"].push_back(image.toJson());
            break;
        }
    }

    // Sauvegarder les modifications
    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open())
    {
        fichierEcriture << data.dump(4);  // Réécrire tout le fichier JSON
        fichierEcriture.close();
    }
}


void Utilisateur::afficherFavoris() const
{
    std::ifstream fichierLecture("utilisateurs.json");
    json data;

    if (fichierLecture.is_open()) {
        fichierLecture >> data;
        fichierLecture.close();
    }

    for (const auto& utilisateurJson : data) {
        if (utilisateurJson["id"] == id) {
            if (utilisateurJson["favoris"].empty()) {
                std::cout << "Pas de favoris pour " << nomUser << "." << std::endl;
            } else {
                std::cout << "Favoris de " << nomUser << " :" << std::endl;
                for (const auto& image : favoris) {
                    std::cout << "- " << image.getNomImage() << std::endl;
                }
            }
            break;
        }
    }
}


void Utilisateur::supprimerImageDeFavoris(const string& nomImage, const string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    json data;

    if (fichierLecture.is_open())
    {
        fichierLecture >> data;  // Charger les utilisateurs existants
        fichierLecture.close();
    }

    // Trouver l'utilisateur par ID et supprimer l'image des favoris
    for (auto& utilisateur : data)
    {
        if (utilisateur["id"] == id)
        {
            auto& favoris = utilisateur["favoris"];
            favoris.erase(std::remove_if(favoris.begin(), favoris.end(),
                                      [nomImage](const json& imageJson) { return imageJson["nomImage"] == nomImage;}
                                      ), favoris.end());
            break;
        }
    }

    // Sauvegarder les modifications
    std::ofstream fichierEcriture(nomFichier);
    if (fichierEcriture.is_open())
    {
        fichierEcriture << data.dump(4);  // Réécrire tout le fichier JSON
        fichierEcriture.close();
    }
}
//La partie moins fun du projet faite le jour J

void afficherCategories(const std::vector<std::string>& categories)
{

}

std::string Utilisateur::choisirCategorie(const std::vector<std::string>& categories)
{
    int choix;
    do {
            std::cout << "Choisissez une categorie parmi les options suivantes :\n";
        for (size_t i = 0; i < categories.size(); ++i) {
            std::cout << i + 1 << ". " << categories[i] << std::endl;
        }

        std::cout << "Entrez le numero de la categorie choisie : ";
        std::cin >> choix;
    } while (choix < 1 || static_cast<size_t>(choix) > categories.size());

    return categories[choix - 1];
}


void Utilisateur::soumettreImage(const string& nomFichier)
{
    int id;
    string nomImage, format, descriptionImage, categorie;
    bool estPublique, estApprouvee;
    vector<string> motsCles;

    // Collecter les données de l'utilisateur
    cout << "=== Soumission d'une nouvelle image ===" << endl;
    cout << "ID de l'image : ";
    cin >> id;
    cin.ignore(); // Ignorer le retour de ligne après le cin
    cout << "Nom de l'image : ";
    getline(cin, nomImage);
    cout << "Format de l'image (ex: jpg, png) : ";
    getline(cin, format);
    cout << "Description de l'image (optionnelle) : ";
    getline(cin, descriptionImage);
    categorie = choisirCategorie({"Nature", "Art", "Architecture", "Technologie", "Mode", "Cuisine", "Sports", "Famille" });
    cout << "Image publique ? (1 pour Oui, 0 pour Non) : ";
    cin >> estPublique;
    estApprouvee = false; // L'image est en attente d'approbation

    int nbMotsCles;
    cout << "Nombre de mots-cles : ";
    cin >> nbMotsCles;
    cin.ignore();
    for (int i = 0; i < nbMotsCles; ++i) {
        string motCle;
        cout << "Mot-clé " << i + 1 << " : ";
        getline(cin, motCle);
        motsCles.push_back(motCle);
    }

    // Créer l'objet Image
    Image nouvelleImage(id, nomImage, format, descriptionImage, categorie, estPublique, estApprouvee, motsCles, get_nomUser());
    nouvelleImage.enregistrerImage(nomFichier);

    cout << "Image soumise avec succes et enregistree dans " << nomFichier << "." << endl;

}


void Utilisateur::quitterApp()
{
    cout << "Merci d'avoir utilise l'application d'images. A bientot !\n";
}

Utilisateur::~Utilisateur()
{
    //dtor
}
