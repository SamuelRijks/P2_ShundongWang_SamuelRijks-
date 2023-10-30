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

    int randomIndex;
    int contComodins = 0;
    for (int i = 0; i < nRow; ++i) {
        node *anterior = nullptr; //secuencia enlazada de cada fila
        for (int j = 0; j < nCol; ++j) {
            int randomIndex = dist(gen);
            char character = availableChars[randomIndex];
            int premiValue = randomIndex;

            if(randomIndex <4 &&randomIndex >= 0){
                Element* element = new Lletra(premiValue, character);
                node* nuevoNodo = new node;
                nuevoNodo->contigut = element;
                nuevoNodo->seguent = nullptr;

                if (anterior) {
                    anterior->seguent = nuevoNodo;  // Enlaza el nuevo nodo con el anterior
                } else {
                    taula[i] = nuevoNodo;  // Si es el primer nodo de la fila, establece taula[i]
                }
                anterior = nuevoNodo;
            }
             else {
                Element* element = new Comodi(premiValue, character);
                node* nuevoNodo = new node;
                nuevoNodo->contigut = element;
                nuevoNodo->seguent = nullptr;
                if (anterior) {
                    anterior->seguent = nuevoNodo;  // Enlaza el nuevo nodo con el anterior
                } else {
                    taula[i] = nuevoNodo;  // Si es el primer nodo de la fila, establece taula[i]
                }
                anterior = nuevoNodo;
            }


        }

    }
}

void Contenidor::afegirElement(Element* element) {
    // 遍历 taula，找到第一个为空的元素位置，并添加 element
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
    // Verificar si la columna está dentro de los límites
    col -= 1;

    // Verificar si la columna está vacía
    if (taula[0][col].contigut == nullptr) {
        // Lanzar una excepción personalizada si la columna está vacía
        throw std::runtime_error("La columna está vacía");

    }

    // Obtener el primer elemento de la columna
    Element *elementoAEliminar = taula[0][col].contigut;

    std::cout << elementoAEliminar->getSimbol() << endl;

    node* firstNode = &taula[0][col];
    Element* removedElement = nullptr;
    while (firstNode != nullptr) {
        node *currentNode = firstNode->seguent;
        if (currentNode != nullptr) {
            //Eliminar el nodo actual
            removedElement = currentNode->contigut;
            std::cout <<removedElement->getSimbol();
            //delete currentNode;
            firstNode->seguent = currentNode->seguent;
        } else {
            // Si no hay ningún siguiente nodo, salimos del ciclo
            break;
        }
    }


return removedElement;



}

Element* Contenidor::EliminaComodi() {
    for (int i = 0; i < nRow; ++i) {
        for (int j = 0; j < nCol; ++j) {
            node* current = taula[i][j].seguent;
            if (current != nullptr && current->contigut->getPremi() == '*') {
                Element* removedElement = current->contigut;
                taula[i][j].seguent = current->seguent;
                delete current;
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
                std::cout << taula[i][j].contigut->getSimbol() << " ";
            } else {
                std::cout << " " << " ";
            }
        }
        std::cout << std::endl;

    }
}



