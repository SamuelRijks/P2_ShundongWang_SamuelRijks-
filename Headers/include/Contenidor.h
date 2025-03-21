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
    int nRow;
    int nCol;
    node **taula;

public:
    Contenidor(int nRow, int nCol);
    ~Contenidor();
    Element* EliminaPerColumna(int col);
    Element* EliminaComodi();
    int getQuants();
    void mostrar();
    void imprimirMatriu(std::string** matriu);

    void afegirElement(Element *element);
};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H
