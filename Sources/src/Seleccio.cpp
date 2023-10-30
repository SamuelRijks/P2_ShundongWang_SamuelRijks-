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
        for (int i = 0; i < mida - 2; ++i) {
            if (array[i] != nullptr && array[i + 1] != nullptr && array[i + 2] != nullptr) {
                if (*array[i] == array[i + 1] && *array[i] == array[i + 2]) {
                    delete array[i];
                    delete array[i + 1];
                    delete array[i + 2];
                    array[i] = nullptr;
                    array[i + 1] = nullptr;
                    array[i + 2] = nullptr;
                    // 更新premiFinal，根据你的需求可能需要计算分数
                    premiFinal += 3;
                    return true;  // 表示成功删除3个相同元素
                }
            }
        }
        return false;  // 没有删除3个相同元素
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
