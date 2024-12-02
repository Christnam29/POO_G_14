#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include <Utilisateur.h>
#include <iostream>
#include <string>
#include <vector>


class Administrateur : public Utilisateur
{
    private:
        std::string nomAdmin;

    public:
        Administrateur(const std::string& nom);

        string GetnomAdmin() { return nomAdmin; }
        void SetnomAdmin(string val) { nomAdmin = val; }

        //Autres methodes
    void afficherCategories(const std::string& nomFichier);
    void ajouterCategorie(const std::string& nomCategorie, const std::string& descriptionCategorie, const std::string& nomFichier);
    void supprimerCategorie(const std::string& nomCategorie, const std::string& nomFichier);
    void filtrerCategorie(const std::string& nomCategorie, const std::string& nomFichier);
    void ajouterUtilisateur(int id, const std::string& nomUser, const std::string& mail, const std::string& motdepasse, const std::string& nomFichier);
    //void suspendreUtilisateur(Utilisateur& utilisateur);
    void supprimerUtilisateur(const std::string& nomUser, const std::string& nomFichier);
    //void modifierInfosUtilisateur(Utilisateur& utilisateur, const std::string& nouvelleInfo);
    void approuverImageSoumise(const string& nomImage, const std::string& nomFichierAttente, const std::string& nomFichierFinal);
    void retirerImage(const std::string& nomImage, std::string& nomFichier);
    //void consulterStatistiques(const Statistiques& stats) const;
    std::vector<Image> rechercherImageParMotCle(const std::vector<Image>& images, const std::string& motCle) const;


    protected:


};


#endif // ADMINISTRATEUR_H
