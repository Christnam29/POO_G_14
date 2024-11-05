#include <iostream>
#include "Utilisateur.h"
#include "Image.h"
#include <sstream>

using namespace std;

Utilisateur::Utilisateur(int identifiant, string name, string email, string mdp)
{
    id = identifiant;
    nomUser= name;
    mail= email;
    motdepasse= mdp;
}

//Accesseurs
int Utilisateur::get_id() const
{
    return id;
}

string Utilisateur::get_nomUser() const
{
    return nomUser;
}

string Utilisateur::get_mail() const
{
    return mail;
}

string Utilisateur::get_motdepasse() const
 {
     return motdepasse;
 }

//Mutateurs
void Utilisateur::set_id(int val)
{
    id = val;
}

void Utilisateur::set_nomUser(string val)
{
    nomUser = val;
}

void Utilisateur::set_mail(string val)
{
    mail = val;
}

void Utilisateur::set_motdepasse(string val)
{
    motdepasse = val;
}

//Autres méthodes
// Méthode pour afficher les informations de l'utilisateur
void Utilisateur::afficherInformations() const {
    std::cout << "ID: " << id << endl;
    std::cout << "Nom: " << nomUser << endl;
    std::cout << "Email: " << mail << endl;
    std::cout << "Password: " << motdepasse << endl; //ligne à mettre en commentaire!!
}

void Utilisateur::sauvegarder(ofstream& fichier) {
    fichier << id << ";" << nomUser << ";" << mail<< ";" << motdepasse << std::endl;
}

vector<Utilisateur> Utilisateur::charger(const std::string& nomFichier) {
    ifstream fichier(nomFichier);
    vector<Utilisateur> utilisateurs;
    string ligne;

    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        int id;
        string name , email, mdp;

        if (getline(iss, ligne, ';')) { // Ici, on lit l'id
            id = stoi(ligne); // Conversion de la chaîne lue en entier
        }

        if (getline(iss, name, ';') &&
            getline(iss, email, ';') &&
            getline(iss, mdp))
            {
                id = stoi(to_string(id));
                utilisateurs.emplace_back(id, name, email, mdp);
            }
    }

    return utilisateurs;
}

bool Utilisateur::seConnecter(const string& name, const string& mdp) const {
    //D'abord il nous faut la liste des utilisateurs avec la méthode "charger"
    vector<Utilisateur> utilisateurs = charger("utilisateurs.txt");

    //Ensuite on vérifie chaque utilisateur
    for (const auto& utilisateur : utilisateurs) {
        if (utilisateur.nomUser == name && utilisateur.motdepasse == mdp) {
            return true; // Connexion réussie
        }
    }

    return false; // Échec de la connexion
}

void Utilisateur::telechargerImage(const string& nomFichier){
    Image nouvelleImage(nomFichier);
    galerie.push_back(nouvelleImage);
    cout << "Image " << nomFichier << " ajoutée à la galerie." << endl;
}

void Utilisateur::afficherGalerie() const {
 cout << "Galerie de " << get_nomUser() << " :" << endl;
    for (const auto& image : galerie) {
        image.afficher();
    }
}

Utilisateur::~Utilisateur()
{
    //dtor
}
