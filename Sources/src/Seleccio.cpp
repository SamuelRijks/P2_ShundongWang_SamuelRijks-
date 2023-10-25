//
// Created by samur on 22/10/2023.
//

#include "../../Headers/include/Seleccio.h"
    Seleccio::Seleccio() {
        for (int i = 0; i < mida; ++i) {
            array[i] = nullptr;
        }
        premiFinal = 0;
    }
    bool Seleccio::afegir(Element* element) {
        for (int i = 0; i < mida; ++i) {
            if (array[i] == nullptr) {
                array[i] = element;
                return true;
            }
        }
        return false;
    }

    bool Seleccio::eliminar3iguals() {
        // 实现删除3个相同元素的逻辑
        // 这里需要你根据具体需求实现
        return false;
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

};
