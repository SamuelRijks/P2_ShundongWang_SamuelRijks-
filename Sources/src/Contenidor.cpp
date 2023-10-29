//
// Created by samur on 20/10/2023.
//

#include "../../Headers/include/Contenidor.h"
#include "../../Headers/include/Lletra.h"
#include "../../Headers/include/Comodi.h"
#include <iostream>
#include <string>
#include <random>


using namespace  std;
Contenidor::Contenidor(int nRow, int nCol) {
    this->nRow = nRow;
    this->nCol = nCol;

    taula = new node*[nRow];
    for (int i = 0; i < nRow; ++i) {
        taula[i] = nullptr;
    }

    char availableChars[] = {'A', 'B', 'C', 'D', '*', '*'};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);

    for (int i = 0; i < nRow; ++i) {
        taula[i] = new node[nCol];
        for (int j = 0; j < nCol; ++j) {
            int randomIndex = dist(gen);
            if(randomIndex<4&&randomIndex>=0){
                char A = availableChars[randomIndex];
                int premiValue = randomIndex;
                Element * element = new Lletra(premiValue,A);
                taula[i][j].contigut = element;
                taula[i][j].seguent = nullptr;
            }else{
                char B = availableChars[randomIndex];
                int premiValue2 = randomIndex;
                Element* element = new Comodi(premiValue2,B);
                taula[i][j].contigut = element;
                taula[i][j].seguent = nullptr;
            }


        }
    }
}

Contenidor::~Contenidor() {
    for (int i = 0; i < nRow; ++i) {
        delete[] taula[i];
    }
    delete[] taula;
}

void Contenidor::afegirElement(Element* element) {
    // 实现将元素添加到表格的逻辑
    // 遍历 taula，找到第一个为空的元素位置，并添加 element
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            if (taula[i][j].contigut == nullptr) {
                taula[i][j].contigut = element;
                return;
            }
        }
    }
}

Element* Contenidor::EliminaPerColumna(int col) {
    if (col < 1 || col > nCol) {
        throw std::out_of_range("Índice de columna fuera de rango");
    }

    col--; // Ajustar el índice a partir de 0

    for (int i = 0; i < nRow; ++i) {
        if (taula[i][col].contigut != nullptr) {
            Element* removedElement = taula[i][col].contigut;
            taula[i][col].contigut = nullptr;
            return removedElement;
        }
    }

    throw std::runtime_error("La columna está vacía");
}

Element* Contenidor::EliminaComodi() {
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            if (taula[i][j].contigut != nullptr && taula[i][j].contigut->getPremi() == '*') {
                Element* removedElement = taula[i][j].contigut;
                taula[i][j].contigut = nullptr;
                return removedElement;
            }
        }
    }

    throw std::runtime_error("No se encontró el comodín");
}

int Contenidor::getQuants() {
    int count = 0;
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            if (taula[i][j].contigut != nullptr) {
                count++;
            }
        }
    }
    return count;
}

void Contenidor::mostrar() {
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            if (taula[i][j].contigut != nullptr) {
                // 使用元素的显示方法
                std::cout << taula[i][j].contigut->getPremi() << " ";
            } else {
                std::cout << " " << " ";
            }
        }
        std::cout << std::endl;
    }
}