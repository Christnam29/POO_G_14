#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Image {

};

class Statistiques {
private:
    int nbreTotalImages;
    int nbreTotalUtilisateurs;
    std::vector<Image> imagesPopulaires; // Liste d'images populaires
    int nbreTelechargements;
    int nbreCategories;

public:
    // Constructeur
    Statistiques() : nbreTotalImages(0), nbreTotalUtilisateurs(0), nbreTelechargements(0), nbreCategories(0) {}

    // M�thodes pour incr�menter les diff�rents compteurs
    void incrementerTelechargement() {
        nbreTelechargements++;
    }

    void incrementerTotalImages() {
        nbreTotalImages++;
    }

    void incrementerTotalUtilisateurs() {
        nbreTotalUtilisateurs++;
    }

    void incrementerTotalCategories() {
        nbreCategories++;
    }

    // M�thode pour calculer le taux de popularit�
    double calculerTauxDePopularite() {
        return nbreTelechargements > 0 ? static_cast<double>(nbreTotalImages) / nbreTelechargements : 0;
    }

    // M�thode pour afficher les statistiques
    void afficherStatistiques() {
        std::cout << "Nombre total d'images : " << nbreTotalImages << std::endl;
        std::cout << "Nombre total d'utilisateurs : " << nbreTotalUtilisateurs << std::endl;
        std::cout << "Nombre de t�l�chargements : " << nbreTelechargements << std::endl;
        std::cout << "Nombre de cat�gories : " << nbreCategories << std::endl;
        std::cout << "Taux de popularit� : " << std::fixed << std::setprecision(2)
                  << calculerTauxDePopularite() << std::endl;
    }
};

int main() {
    Statistiques stats;

    // Exemples d'utilisation
    stats.incrementerTotalImages();
    stats.incrementerTotalUtilisateurs();
    stats.incrementerTelechargement();
    stats.incrementerTotalCategories();

    stats.afficherStatistiques();

    return 0;
}
