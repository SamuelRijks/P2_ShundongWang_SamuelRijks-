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
    return false;
}

bool Element::operator!=(Element *other){
    return true;
}

Element::Element() : simbol('_') {}


