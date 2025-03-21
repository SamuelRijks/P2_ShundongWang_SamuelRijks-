//
// Created by samur on 22/10/2023.
//

#include "../../Headers/include/Seleccio.h"
#include "../../Headers/include/Lletra.h"
#include "../../Headers/include/Comodi.h"

Seleccio::Seleccio() {
    for (int i = 0; i < mida; ++i) {
        array[i] = new Lletra();
    }
    premiFinal = 0;
}
bool Seleccio::afegir(Element* element) {
    for (int i = 0; i < mida; ++i) {
        if (array[i]->getSimbol() == '_') {
            array[i] = element;
            return true;
        }
    }
    return false;
}

bool Seleccio::eliminar3iguals() {
    int numEliminados = 0;

    for (int i = 0; i < mida - 2; ++i) {
        for (int j = i + 1; j < mida - 1; ++j) {
            for (int k = j + 1; k < mida; ++k) {

                if (array[i]->getPremi()!=0 && array[j]->getPremi()!=0 && array[k]->getPremi()!=0) {

                    if (array[i]->operator==(array[j]) &&(array[i]->operator==(array[k]))){

                        array[i] = new Lletra();
                        array[j] = new Lletra();
                        array[k] = new Lletra();
                        premiFinal += 150;
                        numEliminados += 3;
                    }

                    else if ((array[i]->getPremi() == array[j]->getPremi() && array[k]->getPremi() > 4) ||
                             (array[i]->getPremi() == array[k]->getPremi() && array[j]->getPremi() > 4) ||
                             (array[j]->getPremi() == array[k]->getPremi() && array[i]->getPremi() > 4)) {

                        array[i] = new Lletra();
                        array[j] = new Lletra();
                        array[k] = new Lletra();
                        premiFinal += 150;
                        numEliminados += 3;
                    }
                }
            }
        }
    }

    return numEliminados > 0;
}

int Seleccio::getPremiFinal() {
    return premiFinal;
}

void Seleccio::mostrar() {
    for (int i = 0; i < mida; ++i) {
        if (array[i] != nullptr) {

            array[i]->mostrar();

        }
    }

    std::cout << std::endl;

}

bool Seleccio::getLength(){
    int length=0;
    for (int i = 0; i < mida; ++i) {
        if (array[i]->getSimbol() != '_') {
            length++;

        }
    }

    return length == 6;
}

Seleccio::~Seleccio() {
    for (int i = 0; i < mida; i++) {
        delete array[i];
    }
}
