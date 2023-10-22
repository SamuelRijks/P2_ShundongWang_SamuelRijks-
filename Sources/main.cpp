#include <iostream>

int main() {
    cout<<"Hello World";

    Lletra c; //invoca el constructor per defecte
    Lletra b(50,'B');

    //Element e; ERROR: no es pot inicialitzar un objecte d'una classe abstracte
    //Element seleccionades[6]; MATEIX ERROR

    Element *e;
    e= new Lletra(50,'A');

    Element *seleccionades;
    seleccionades = new Lletra[6];
    // crea un array del tipus Element però inicialitzem amb el constructor per defecte de la filla Lletra

    return 0;
}
