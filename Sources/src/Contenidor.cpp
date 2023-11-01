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

    taula = new node*[nCol];
    for (int i = 0; i < nCol; ++i) {
        taula[i] = nullptr;
    }

    std::vector<int> numbers = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 1, 1, 1, 2, 5, 6, 3, 3, 3, 1, 1, 1};
    char availableChars[] = {'A', 'A', 'B', 'C', 'D', '*', '*'};

    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < nCol; ++i) {
        node *anterior = nullptr;
        for (int j = 0; j < nRow; ++j) {
            std::uniform_int_distribution<> distIndex(0, numbers.size() - 1);
            int index = distIndex(gen);
            int randomIndex = numbers[index];
            numbers.erase(numbers.begin() + index);
            if (randomIndex >= 0 && randomIndex < 5) {
                char character = availableChars[randomIndex];
                Element* element = new Lletra(randomIndex, character);
                node* nuevoNodo = new node;
                nuevoNodo->contigut = element;
                nuevoNodo->seguent = nullptr;
                if (anterior != nullptr) {
                    anterior->seguent = nuevoNodo;
                } else {
                    taula[i] = nuevoNodo;
                }
                anterior = nuevoNodo;
            }
            else if( randomIndex >=5){
                char character = availableChars[randomIndex];
                Element* element = new Comodi(randomIndex, character);
                node* nuevoNodo = new node;
                nuevoNodo->contigut = element;
                nuevoNodo->seguent = nullptr;
                if (anterior != nullptr) {
                    anterior->seguent = nuevoNodo;
                } else {
                    taula[i] = nuevoNodo;
                }
                anterior = nuevoNodo;
            }else {
            }
        }
    }
}

void Contenidor::afegirElement(Element* element) {
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            node* current = taula[i][j].seguent;
            if (current == nullptr) {
                node* newNode = new node;
                newNode->contigut = element;
                newNode->seguent = nullptr;
                taula[i][j].seguent = newNode;
                return;
            }
            while (current->seguent != nullptr) {
                current = current->seguent;
            }
            node* newNode = new node;
            newNode->contigut = element;
            newNode->seguent = nullptr;
            current->seguent = newNode;
            return;
        }
    }
}

Element* Contenidor::EliminaPerColumna(int col) {
    col -= 1;
    if (taula[col] == nullptr) {
        throw std::invalid_argument("La columna está vacía");
    }

    node* firstNode = taula[col];
    Element *elementoAEliminar = firstNode->contigut;
    taula[col] = taula[col]->seguent;
    return elementoAEliminar;
}

Element* Contenidor::EliminaComodi() {
    Comodi *comodi = new Comodi();
    for (int i = 0; i < nCol; i++) {
        node* actual = taula[i];
        node* anterior = nullptr;
        while (actual != nullptr) {
            Element* contenido = actual->contigut;
            if (contenido->operator==(comodi)) {
                if(anterior == nullptr){
                    taula[i] = taula[i]->seguent;
                }
                else{
                    anterior->seguent = actual->seguent;
                }
                delete actual;
                return contenido;
            }
            anterior = actual;
            actual = actual->seguent;
        }
    }

    throw std::invalid_argument("No se ha encontrado ningún comodín en la taula.");
}

int Contenidor::getQuants() {
    int count = 0;
    for (int i = 0; i < nCol; ++i) {
        node* currentNode = taula[i];
        while (currentNode != nullptr) {
            count++;
            currentNode = currentNode->seguent;
        }
    }
    return count;
}

void Contenidor::mostrar() {
    std::string** taulaMostrar = new std::string*[nRow];
    for (int i = 0; i < nRow; i++) {
        taulaMostrar[i] = new std::string[nCol];
    }
    for (int i = 0; i < nCol; i++) {
        node* actual = taula[i];
        int cont=0;
        while (actual != nullptr) {

            Element* contenido = actual->contigut;

            taulaMostrar[cont][i] = contenido->getSimbol();

            actual = actual->seguent;
            cont++;
        }
    }
    imprimirMatriu(taulaMostrar);
    for (int i = 0; i < nRow; i++) {
        delete[] taulaMostrar[i];
    }
    delete[] taulaMostrar;
}

void Contenidor::imprimirMatriu(std::string** matriu){
    for (int i = 0; i < nRow; i++) {
        if(i==0){
            for (int j = 1; j < nCol+1; j++) {
                std::cout << j;
                std::cout <<" ";
            }
            std::cout << std::endl;
        }
        for (int j = 0; j < nCol; j++) {
            std::cout << matriu[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Contenidor::~Contenidor() {
    delete taula;
}






