//
// Created by samur on 22/10/2023.
//

#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H

#include <iostream>
#include "Element.h"


class Lletra : public Element {

private:
    int premi;
public:
    Lletra() : Element('_') { this->premi = 0; }
    Lletra(int premi, char simbol) : Element(simbol) { this->premi = premi;}

    int getPremi() override{
        return this->premi;
    }
    char getSimbol() override {
        return Element::getSimbol(); // 或者提供特定的实现
    }

    bool operator==(Element *other) override {
       return false;
    }

    bool operator!=(Element *other) override {
        return true;
    }

};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H
