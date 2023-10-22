//
// Created by samur on 22/10/2023.
//

#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H


#include "Element.h"

class Lletra : public Element {

private:
    int premi;

public:
    Lletra();
    Lletra(int premi, char simbol) : Element(simbol)
    { this->premi = premi;}

    int getPremi() override{
        return this->premi;
    }

};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H
