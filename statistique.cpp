#include <iostream>
#include <vector>
#include <string>

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

    // Méthodes pour incrémenter les différents compteurs
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

    // Méthode pour calculer le taux de popularité (à définir selon tes besoins)
    double calculerTauxDePopularite() {
        // Exemple de calcul du taux de popularité
        return nbreTelechargements > 0 ? static_cast<double>(nbreTotalImages) / nbreTelechargements : 0;
    }

    // Méthode pour afficher les statistiques
    void afficherStatistiques() {
        std::cout << "Nombre total d'images : " << nbreTotalImages << std::endl;
        std::cout << "Nombre total d'utilisateurs : " << nbreTotalUtilisateurs << std::endl;
        std::cout << "Nombre de telechargements : " << nbreTelechargements << std::endl;
        std::cout << "Nombre de categories : " << nbreCategories << std::endl;
        std::cout << "Taux de popularite : " << calculerTauxDePopularite() << std::endl;
        // Affiche les images populaires si nécessaire
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
