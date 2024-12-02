#include "Categorie.h"
#include <iostream>

// Constructeur
Categorie::Categorie(int id, const std::string& nomCategorie)
    : id(id), nomCategorie(nomCategorie) {}

// Getters
int Categorie::getId() const {
    return id;
}

std::string Categorie::getNomCategorie() const {
    return nomCategorie;
}

std::vector<Image> Categorie::getImages() const {
    return images;
}

// Methode afficherCategorie
void Categorie::afficherCategorie() const {
    std::cout << "Categorie : " << nomCategorie << " (ID: " << id << ")\n";
    std::cout << "Images associees :\n";
    for (const auto& image : images) {
        image->afficherImage();
    }
}
