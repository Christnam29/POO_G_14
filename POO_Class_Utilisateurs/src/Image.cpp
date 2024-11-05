#include "Image.h"
#include <iostream>
using namespace std;


Image::Image(const string& nomFichier)
{
    nomImage = nomFichier;
}

void Image::afficher() const {
    cout << "Nom de fichier : " << nomImage << endl;
}

Image::~Image()
{
    //dtor
}
