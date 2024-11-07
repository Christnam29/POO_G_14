#include <iostream>
#include <string>
#include <vector>
#include <map>

class Image; 
class Utilisateur; 
class Statistiques; 

class Administrateur {
private:
    std::string nomAdmin;

public:
   
    Administrateur(const std::string& nom) : nomAdmin(nom) {}

    
    void creerCategorie(const std::string& nomCategorie);
    void supprimerCategorie(const std::string& nomCategorie);
    void filtrerCategorie(const std::string& nomCategorie);
    void ajouterUtilisateur(Utilisateur& utilisateur);
    void suspendreUtilisateur(Utilisateur& utilisateur);
    void supprimerUtilisateur(Utilisateur& utilisateur);
    void modifierInfosUtilisateur(Utilisateur& utilisateur, const std::string& nouvelleInfo);
    void approuverImageSoumise(Image& image);
    void retirerImage(Image& image);
    void consulterStatistiques(Statistiques& stats);
    std::vector<Image> rechercherImageParMotCle(const std::string& motCle);
};


void Administrateur::creerCategorie(const std::string& nomCategorie) {
    std::cout << "Création de la catégorie : " << nomCategorie << std::endl;
    
}

void Administrateur::supprimerCategorie(const std::string& nomCategorie) {
    std::cout << "Suppression de la catégorie : " << nomCategorie << std::endl;
    
}

void Administrateur::filtrerCategorie(const std::string& nomCategorie) {
    std::cout << "Filtrage de la catégorie : " << nomCategorie << std::endl;
    
}

void Administrateur::ajouterUtilisateur(Utilisateur& utilisateur) {
    std::cout << "Ajout de l'utilisateur" << std::endl;
    
}

void Administrateur::suspendreUtilisateur(Utilisateur& utilisateur) {
    std::cout << "Suspension de l'utilisateur" << std::endl;
   
}

void Administrateur::supprimerUtilisateur(Utilisateur& utilisateur) {
    std::cout << "Suppression de l'utilisateur" << std::endl;
    

void Administrateur::modifierInfosUtilisateur(Utilisateur& utilisateur, const std::string& nouvelleInfo) {
    std::cout << "Modification des informations de l'utilisateur" << std::endl;
   
}

void Administrateur::approuverImageSoumise(Image& image) {
    std::cout << "Approbation de l'image soumise" << std::endl;
   

void Administrateur::retirerImage(Image& image) {
    std::cout << "Retrait de l'image" << std::endl;
   
}

void Administrateur::consulterStatistiques(Statistiques& stats) {
    std::cout << "Consultation des statistiques" << std::endl;
   

std::vector<Image> Administrateur::rechercherImageParMotCle(const std::string& motCle) {
    std::cout << "Recherche d'image par mot-clé : " << motCle << std::endl;
    std::vector<Image> resultats;
   
    return resultats;
}
