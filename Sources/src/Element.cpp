//
// Created by samur on 20/10/2023.
//
#include "../../Headers/include/Element.h"

char Element::getSimbol() {
    return simbol;
}

int Element::getPremi() {
    return 0;
}

bool Element::operator==(Element *other) {
    return this->getPremi()==other->getPremi();
}

bool Element::operator!=(Element *other){
    return this->getPremi()==other->getPremi();
}
void Element::mostrar() {

    std::cout << "Simbol: " << simbol << " Premi: " << getPremi() << std::endl;
}


Element::Element() : simbol('_') {

}

Element::Element(char simbol) {
    this->simbol=simbol;
}

Element::~Element() {

}


