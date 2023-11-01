//
// Created by samur on 22/10/2023.
//

#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_SELECCIO_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_SELECCIO_H

#include <iostream>
#include "Element.h"

class Seleccio {
private:
    static const int mida = 6;
    Element *array[mida];
    int premiFinal;

public:
    Seleccio();
    ~Seleccio();
    bool afegir(Element*);
    bool eliminar3iguals();
    int getPremiFinal();
    void mostrar();
    bool getLength();

};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_SELECCIO_H
