//
// Created by samur on 20/10/2023.
//

#include "../../Headers/include/Contenidor.h"
#include <iostream>
#include <string>

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
}

Element *Contenidor::EliminaPerColumna(int col) {
    // 实现按列删除元素的逻辑
    return nullptr; // 仅作示例
}

Element *Contenidor::EliminaComodi() {
    // 实现删除通配符元素的逻辑
    return nullptr; // 仅作示例
}

int Contenidor::getQuants() {
    // 实现获取元素数量的逻辑
    return 0; // 仅作示例
}

void Contenidor::mostrar() {
    // 实现显示表格的逻辑
}