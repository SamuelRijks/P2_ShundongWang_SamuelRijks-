//
// Created by samur on 22/10/2023.
//

#include "../../Headers/include/Comodi.h"

Comodi::Comodi() : Element('*') {
    this->premi = 0;
}

Comodi::Comodi(int premi, char simbol) : Element(simbol) {
    this->premi = premi;
}

int Comodi::getPremi() {
    return this->premi;
}

char Comodi::getSimbol() {
    return Element::getSimbol();
}

bool Comodi::operator==(Element *other) {
    return false;
}

bool Comodi::operator!=(Element *other) {
    return true;
}

