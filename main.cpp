#include <iostream>
#include "Image.h"

int main() {
    //Cr�ez un objet Image pour tester
    Image img(1, "Exemple Image", "jpg", "Description de l�image", nullptr, true, "http://url.com","2024-11-01", {"mot1","mot2"}) ;

    // Appelez la m�thode afficherImage pour voir les d�tails
    img.afficherImage();

    return 0 ;
}




