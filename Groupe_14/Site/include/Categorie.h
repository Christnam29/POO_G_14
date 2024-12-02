#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>
#include <vector>
#include "Image.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Categorie {
private:
    int id;
    std::string nomCategorie;
    std::vector <Image> images;

public:
    // Constructeur
    Categorie(int id, const std::string& nomCategorie);

    // Getters
    int getId() const;
    std::string getNomCategorie() const;
    std::vector<Image> getImages() const;

    // Methode d'affichage
    void afficherCategorie() const;

    nlohmann::json toJson() const {
        nlohmann::json j;
        j["nomCategorie"] = nomCategorie;
        return j;
    }
};

#endif // CATEGORIE_H
