#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <fstream>
#include <vector>
#include "Image.h"

using namespace std;

class Utilisateur
{
    private:
        int id;
        string nomUser;
        string mail;
        string motdepasse;
        vector <Image> galerie;


    public:
        //Constructeurs
        Utilisateur(int id, string name, string email, string mdp);

        //Destructeur
        ~Utilisateur();

        //Accesseurs
        int get_id()const ;
        string get_nomUser() const;
        string get_mail()const;
        string get_motdepasse()const;

        //Mutateurs
        void set_id(int val);
        void set_nomUser(string val);
        void set_mail(string val);
        void set_motdepasse(string val);


        //Autres
        void afficherInformations() const;
        void sauvegarder(ofstream& fichier); //pour enregistrer des utilisateurs
        static vector<Utilisateur> charger(const string& nomFichier);
        bool seConnecter(const string& name, const string& mdp) const;

        void telechargerImage(const std::string& nomFichier);
        void afficherGalerie() const;





    protected:

};

#endif // UTILISATEUR_H
