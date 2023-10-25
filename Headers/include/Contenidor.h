//
// Created by samur on 20/10/2023.
//
#include <iostream>
#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H


#include "Element.h"

class Contenidor {
private:
    struct node{
        Element *contigut;
        node *seguent;
    };

    node *taula;

public:
    Contenidor(int nRow, int nCol);
    ~Contenidor();

    void afegirElement(Element*);
    Element* EliminaPerColumna(int col);
    Element* EliminaComodi();
    int getQuants();
    void mostrar();

};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H
