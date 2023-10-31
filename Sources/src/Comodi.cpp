
#include "../../Headers/include/Comodi.h"

Comodi::Comodi() {
    this->premi = 0;
}

Comodi::Comodi(int premi, char simbol) : Element(simbol) {
    this->premi = premi;
}

int Comodi::getPremi() {
    return premi;
}

char Comodi::getSimbol() {
    return Element::getSimbol();
}

bool Comodi::operator==(Element *other) {
    return true;
}

bool Comodi::operator!=(Element *other) {
    return false;
}

void Comodi::mostrar() {
    std::cout << getSimbol();
}