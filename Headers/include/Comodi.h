//
// Created by samur on 22/10/2023.
//
#include <iostream>
#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_COMODI_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_COMODI_H
#include <iostream>
#include "Element.h"

class Comodi:public Element{
private:
    int premi;
public:
    Comodi() : Element('*') {}
    Comodi(int premi, char simbol) : Element('*') {
        this->premi = premi;
    }

    int getPremi() override {
        return this->premi;
    }    char getSimbol() override {
        return Element::getSimbol(); // 或者提供特定的实现
    }

    bool operator==(Element *other) override {
        return false;
    }

    bool operator!=(Element *other) override {
        return true;
    }
};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_COMODI_H
