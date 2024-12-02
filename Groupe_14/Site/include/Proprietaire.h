#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H

#include "Utilisateur.h"

class Proprietaire : public Utilisateur {
public:
    // Constructeur
    Proprietaire(int id, const std::string& name, const std::string& email, const std::string& mdp);

    // Methodes
    void supprimerImagePubliee(const std::string& nomImage);
    void changerVisibilite(const std::string& nomImage, bool visibilite);

};

#endif // PROPRIETAIRE_H
