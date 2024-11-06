#include "Image.h"
#include <iostream>

// Constructeurs
Image ::Image(int id, const std ::string& nomImage, const std ::string& format,
             const std ::string& descriptionImage, Categorie* categorie, bool estPublique,
             const std ::string& url, const std ::string& dateAjout,
             const std ::vector<std ::string>& motsCles)
    : id(id), nomImage(nomImage), format(format), descriptionImage(descriptionImage),
      categorie(categorie), estPublique(estPublique), url(url), dateAjout(dateAjout),
      motsCles(motsCles) {}

// Getters
int Image ::getId() const { return id; }
std::string Image ::getNomImage() const { return nomImage; }
std::string Image ::getFormat() const { return format; }
std::string Image ::getDescriptionImage() const { return descriptionImage; }
Categorie* Image ::getCategorie() const { return categorie; }
bool Image ::getEstPublique() const { return estPublique; }
std::string Image ::getUrl() const { return url; }
std::string Image ::getDateAjout() const { return dateAjout; }
std::vector<std ::string> Image ::getMotsCles() const { return motsCles ; }

// Setters
void Image ::setId(int id) { this->id = id; }
void Image ::setNomImage(const std ::string& nomImage) { this->nomImage = nomImage; }
void Image ::setFormat(const std ::string& format) { this->format = format; }
void Image ::setDescriptionImage(const std ::string& descriptionImage) { this->descriptionImage = descriptionImage; }
void Image ::setCategorie(Categorie* categorie) { this->categorie = categorie; }
void Image ::setEstPublique(bool estPublique) { this->estPublique = estPublique; }
void Image ::setUrl(const std ::string& url) { this->url = url ; }
void Image ::setDateAjout(const std ::string& dateAjout) { this->dateAjout = dateAjout; }
void Image ::setMotsCles(const std ::vector<std ::string>& motsCles) { this->motsCles = motsCles; }

// Méthodes spécifiques
void Image ::afficherImage() const {
    std::cout << "ID : "  << id << std ::endl;
    std::cout << "Nom : "  << nomImage << std ::endl;
    std::cout << "Format : "  << format << std ::endl;
    std::cout << "Description : "  << descriptionImage << std ::endl;
    std::cout << "URL : " << url << std ::endl ;
    std::cout << "Date d’ajout : "  << dateAjout << std ::endl ;
    std::cout << "Est publique : "  << (estPublique ? "Oui" : "Non") << std ::endl ;
    std::cout << "Mots-clés : " ;
    for (const auto& mot : motsCles) {
        std ::cout << mot << " ";
    }
    std::cout << std ::endl;
}

