//
// Created by samur on 22/10/2023.
//

#include "../../Headers/include/Lletra.h"
#include "../../Headers/include/Element.h"

Lletra::Lletra(int premi, char simbol) : Element(simbol){
    this->premi = premi;
}

int Lletra::getPremi() {
    return this->premi;
}