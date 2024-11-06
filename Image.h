#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

class Categorie;  // Déclarations anticipées des classes Categories

class Image {
private :
    int id;
    std::string nomImage;
    std::string format;
    std::string descriptionImage;
    Categorie* categorie;
    bool estPublique;
    std::string url;
    std::string dateAjout;
    std::vector<std ::string> motsCles;

public :
    // Constructeurs
    Image(int id, const std ::string& nomImage, const std ::string& format,
          const std ::string& descriptionImage, Categorie* categorie, bool estPublique,
          const std ::string& url, const std ::string& dateAjout,
          const std ::vector<std ::string>& motsCles);

    // Getters
    int getId() const;
    std::string getNomImage() const;
    std::string getFormat() const;
    std::string getDescriptionImage() const;
    Categorie* getCategorie() const;
    bool getEstPublique() const;
    std::string getUrl() const;
    std::string getDateAjout() const;
    std::vector<std ::string> getMotsCles() const;

    // Setters
    void setId(int id);
    void setNomImage(const std ::string& nomImage);
    void setFormat(const std ::string& format) ;
    void setDescriptionImage(const std ::string& descriptionImage);
    void setCategorie(Categorie* categorie);
    void setEstPublique(bool estPublique);
    void setUrl(const std ::string& url);
    void setDateAjout(const std ::string& dateAjout);
    void setMotsCles(const std ::vector<std ::string>& motsCles);

    // Méthodes spécifiques
    void afficherImage() const;
} ;

#endif // IMAGE_H

