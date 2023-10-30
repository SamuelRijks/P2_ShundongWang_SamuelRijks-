//
// Created by samur on 22/10/2023.
//
#include "../../Headers/include/Lletra.h"

Lletra::Lletra() {

    this->premi = 0;
}

Lletra::Lletra(int premi, char simbol) : Element(simbol) {
    this->premi = premi;
}

int Lletra::getPremi() {
    return this->premi;
}

char Lletra::getSimbol() {
    return Element::getSimbol();
}

bool Lletra::operator==(Element *other) {
    return false;
}

bool Lletra::operator!=(Element *other) {
    return true;
}

void Lletra::mostrar() {
    std::cout << getSimbol() << " ";
}

