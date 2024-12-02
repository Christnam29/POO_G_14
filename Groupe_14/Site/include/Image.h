#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>
#include <string>
#include "json.hpp"

using json = nlohmann::json;


using namespace std;



class Image {
private :
    int id;
    std::string nomImage;
    std::string format;
    std::string descriptionImage;
    string categorie;
    bool estPublique;
    bool estApprouvee;
    vector<string> motsCles;
    std::string nomUtilisateur;

public :
    // Constructeurs
    Image(int id, const std ::string& nomImage, const std ::string& format,
          const std ::string& descriptionImage="", const std::string& catg="", bool estPublique=false,
          bool estApprouvee=false, const std ::vector<std ::string>& keywords={}, const std::string& nom= ""): id(id), nomImage(nomImage),
          descriptionImage(descriptionImage), categorie(catg), estPublique(estPublique), estApprouvee(estApprouvee),
          motsCles(keywords), nomUtilisateur(nom) {}

    // Constructeur à partir d'un objet JSON
    Image(const nlohmann::json& json) {
        id = json.value("id", 0);
        nomImage = json.value("nomImage", "");
        format = json.value("format", "");
        descriptionImage = json.value("descriptionImage", "");
        categorie = json.value("categorie", "");
        estPublique = json.value("estPublique", true);
        estApprouvee = json.value("estApprouvee", false);
        motsCles = json.value("motsCles", std::vector<std::string>{});

    }

    // Getters
    int getId() const {return id;}
    std::string getNomImage() const {return nomImage;};
    std::string getFormat() const {return format;}
    std::string getDescriptionImage() const {return descriptionImage;}
    string getCategorie() const {return categorie;}
    bool getEstPublique() const {return estPublique;}
    bool getEstApprouvee () const {return estApprouvee;}
    std::vector<std ::string> getMotsCles() const {return motsCles;}

    // Setters
    void setId(int val) { id = val; }
    void setNomImage(const std ::string& val){ nomImage = val; }
    void setFormat(const std ::string& val) { format = val; }
    void setDescriptionImage(const std ::string& val) { descriptionImage = val; }
    void setCategorie(const string& val) { categorie = val; }
    void setEstPublique(bool val){ estPublique = val; }
    void setEstApprouvee (bool val) { estApprouvee = val; }
    void setMotsCles(const std ::vector<std ::string>& val) { motsCles = val; }

    // Méthodes spécifiques
     json toJson() const {
        return {
            {"id", id},
            {"nomImage", nomImage},
            {"format", format},
            {"descriptionImage", descriptionImage},
            {"categorie", categorie},
            {"estPublique", estPublique},
            {"estApprouvee", estApprouvee},
            {"motsCles", motsCles},
            {"nomUtilisateur", nomUtilisateur}
        };
    }
    void afficherImage() const;

    void enregistrerImage (const std::string& nomFichier);

};

#endif // IMAGE_H


