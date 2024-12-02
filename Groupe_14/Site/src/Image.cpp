#include "Image.h"
#include "Categorie.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;


void Image::enregistrerImage (const std::string& nomFichier){
    json data;

    std::ifstream fichierLecture(nomFichier);
    if (fichierLecture.is_open())
    {
        fichierLecture >> data;
        fichierLecture.close();
    }

    json nouvelleImageJson = {
        {"id", id},
        {"nomImage",nomImage},
        {"format", format},
        {"descriptionImage",descriptionImage},
        {"categorie", categorie},
        {"estPublique", estPublique},
        {"estApprouvee", estApprouvee},
        {"motsCles", motsCles},
        {"nomUtilisateur", nomUtilisateur}
    };
    data.push_back(nouvelleImageJson);

    std::ofstream fichierSortie(nomFichier);
    fichierSortie << data.dump(4); // Écrire avec indentation
    fichierSortie.close();

    //std::cout << "Image ajoutee avec succes." << std::endl;
}

