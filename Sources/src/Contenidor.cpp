//
// Created by samur on 20/10/2023.
//

#include "../../Headers/include/Contenidor.h"
#include <iostream>
#include <string>
#include <random>


using namespace  std;

Contenidor::Contenidor(int nRow, int nCol) {
    int totatElements = 24;

    this->taula = new node[6];

    // Create an array of available characters and asterisks
    char availableChars[] = {'A', 'B', 'C', 'D', '*', '*'};

    std::random_device rd;
    std::mt19937 gen(rd());

}
Contenidor::~Contenidor() {
    for (int i = 0; i < nRow; ++i) {
        node *current = taula[i];
        while (current != nullptr) {
            node *temp = current;
            current = current->seguent;
            delete temp->contingut;
            delete temp;
        }
    }
    delete[] taula;
}

void Contenidor::afegirElement(Element *element) {
    // 实现将元素添加到表格的逻辑
    // 遍历 taula，找到第一个为空的元素位置，并添加 element
    for (int i = 0; i < nRow; ++i) {
        node *current = taula[i];
        while (current != nullptr) {
            if (current->contingut == nullptr) {
                current->contingut = element;
                return;
            }
            current = current->seguent;
        }
    }
}

Element *Contenidor::EliminaPerColumna(int col) {
    if (col < 0 || col >= nCol) {
        throw std::out_of_range("Column index out of range"); // 抛出异常，表示列索引超出范围
    }

    for (int i = 0; i < nRow; ++i) {
        node *current = taula[i];
        for (int j = 0; j < col; ++j) {
            if (current != nullptr) {
                current = current->seguent;
            }
        }

        if (current != nullptr && current->contingut != nullptr) {
            Element *removedElement = current->contingut;
            current->contingut = nullptr;
            return removedElement;
        }
    }

    throw std::runtime_error("Column is empty"); // 抛出异常，表示列为空
}

Element *Contenidor::EliminaComodi() {
    int count = 0;
    for (int i = 0; i < nRow; ++i) {
        node *current = taula[i];
        while (current != nullptr) {
            if (current->contingut != nullptr) {
                count++;
            }
            current = current->seguent;
        }
    }
    return count;
}

int Contenidor::getQuants() {
    // 实现获取元素数量的逻辑
    int count = 0;
    for (int i = 0; i < nRow; ++i) {
        node *current = taula[i];
        while (current != nullptr) {
            if (current->contingut != nullptr) {
                count++;
            }
            current = current->seguent;
        }
    }
    return count;
}

void Contenidor::mostrar() {
    // 实现显示表格的逻辑
    for (int i = 0; i < nRow; ++i) {
        node *current = taula[i];
        while (current != nullptr) {
            if (current->contingut != nullptr) {
                // 使用元素的显示方法
                current->contingut->mostrar();
            }
            current = current->seguent;
        }
    }
}