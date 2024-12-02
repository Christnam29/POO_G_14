#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <fstream>
#include <vector>
#include "Image.h"


class Utilisateur
{
private:
    int id;
    std::string nomUser;
    std::string mail;
    std::string motdepasse;
    std::vector<Image> galerie;
    std::vector<Image> favoris;

public:
    //Constructeurs
    Utilisateur (); //J'utilise un constructeur szns paramètre pour créer des utilisateurs par défaut
    Utilisateur(int id, std::string name, std::string email, std::string mdp, std::vector<Image> glrie, std::vector<Image> fvs);

    //Destructeur
    ~Utilisateur();

    //Accesseurs
    int get_id()const ;
    std::string get_nomUser() const;
    std::string get_mail()const;
    std::string get_motdepasse()const;

    //Mutateurs
    void set_id(int val);
    void set_nomUser(std::string val);
    void set_mail(std::string val);
    void set_motdepasse(std::string val);


    //Autres
    void afficherInformations() const;
    void sauvegarder(const std::string& nomFichier); //pour enregistrer des utilisateurs
    std::vector<Utilisateur> charger(const std::string& nomFichier);
    bool seConnecter(const std::string& name, const std::string& mdp, const std::string& nomFichier);

    void telechargerImage(const Image& image, const std::string& nomFichier);
    void afficherGalerie() const;
    void supprimerImageDeGalerie (const std::string& nomImage, const std::string& nomFichier);

    void liker(const Image& image, const std::string& nomFichier);
    void supprimerImageDeFavoris(const std::string& nomImage, const std::string& nomFichier);
    void afficherFavoris() const;

    std::string choisirCategorie(const std::vector<std::string>& categories);
    void soumettreImage(const string& nomFichier);

    void quitterApp();

    json to_json() const;





protected:

};

#endif // UTILISATEUR_H
