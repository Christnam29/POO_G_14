#include "Proprietaire.h"
#include "Image.h"
#include <iostream>

// Constructeur
Proprietaire::Proprietaire(int id, const std::string& name, const std::string& email, const std::string& mdp)
    : Utilisateur(id, name, email, mdp) {}

// Methode pour supprimer une image publiee de la galerie
void Proprietaire::supprimerImagePubliee(const std::string& nomImage) {
    // Recherche dans la galerie d'images de l'utilisateur
    auto it = galerie.begin();
    while (it != galerie.end()) {
        if (it->getNomImage() == nomImage) {
            it = galerie.erase(it);  // Suppression de l'image
            std::cout << "Image " << nomImage << " supprim�e de la galerie.\n";
            return;
        } else {
            ++it;
        }
    }
    std::cout << "Image " << nomImage << " non trouv�e dans la galerie.\n";
}

// Methode pour changer la visibilite d'une image (publique ou priv�e)
void Proprietaire::changerVisibilite(const std::string& nomImage, bool visibilite) {
    for (auto& image : galerie) {
        if (image.getNomImage() == nomImage) {
            image.setEstPublique(visibilite);  // Modification de la visibilit�
            std::cout << "Visibilite de l'image " << nomImage << " change.\n";
            return;
        }
    }
    std::cout << "Image " << nomImage << " non trouve dans la galerie.\n";
}
