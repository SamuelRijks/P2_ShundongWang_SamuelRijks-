//
// Created by samur on 22/10/2023.
//

#include "../../Headers/include/Seleccio.h"
#include "../../Headers/include/Lletra.h"

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
    int numEliminados = 0;  // 记录已经删除的元素个数
    for (int i = 0; i < mida - 2; ++i) {
        for (int j = i + 1; j < mida - 1; ++j) {
            for (int k = j + 1; k < mida; ++k) {
                if (array[i] && array[j] && array[k]) {
                    if ((array[i]->getSimbol() == array[j]->getSimbol()==array[k]->getSimbol() )||
                            (array[i]->getSimbol() == array[j]->getSimbol() && array[k]->getSimbol() == '*') ||
                            (array[i]->getSimbol() == array[k]->getSimbol() && array[j]->getSimbol() == '*') ||
                            (array[j]->getSimbol() == array[k]->getSimbol() && array[i]->getSimbol() == '*')) {
                        // 找到三个相同或两个相同一个为 "*" 的情况
                        delete array[i];
                        delete array[j];
                        delete array[k];
                        array[i] = nullptr;
                        array[j] = nullptr;
                        array[k] = nullptr;
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
            // 使用元素的显示方法
            array[i]->mostrar();

        }
    }

    std::cout << std::endl;

};
