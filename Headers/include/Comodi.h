//
// Created by samur on 22/10/2023.
//
#include <iostream>
#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_COMODI_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_COMODI_H
#include <iostream>
#include "Element.h"

class Comodi : public Element {
private:
    int premi;

public:
    Comodi();
    Comodi(int premi, char simbol);

    int getPremi() override;
    char getSimbol() override;

    bool operator==(Element *other) override;
    bool operator!=(Element *other) override;
    void mostrar() override;


};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_COMODI_H
