#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>

using namespace std;


class Image
{
    private:
        string nomImage;

    public:
        Image(const string& nomFichier);
        ~Image();

        void afficher() const;


        string GetnomFichier() { return nomImage; }
        void SetnomFichier(string val) { nomImage = val; }

    protected:

};

#endif // IMAGE_H
