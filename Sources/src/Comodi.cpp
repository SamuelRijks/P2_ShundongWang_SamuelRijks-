
#include "../../Headers/include/Comodi.h"

Comodi::Comodi() : Element('_'){
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
        return false;
}

bool Comodi::operator!=(Element *other) {
        return true;
}









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

