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

    int contComodins = 0;
    for (int i = 0; i < nCol; ++i) {
        node *anterior = nullptr; //secuencia enlazada de cada fila
        for (int j = 0; j < nRow; ++j) {
            if (numbers.empty()) {
                // 检查numbers数组是否为空
                // 如果为空，你可以选择一个默认字符或采取其他操作
                break;
            }

            // 随机生成一个索引，这个索引将用于从numbers数组中获取数字
            std::uniform_int_distribution<> distIndex(0, numbers.size() - 1);
            int index = distIndex(gen);

            // 从numbers数组中获取一个数字并从数组中删除
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
                // 处理 randomIndex 超出范围的情况
                // 可以选择默认字符或其他操作
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
    if (taula[col] == nullptr) {
        // Lanzar una excepción personalizada si la columna está vacía
        std::cout<<"La columna está vacía"<<std::endl;
        return nullptr;
    }
    // Obtener el primer elemento de la columna

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
                    // Suponiendo que esComodi() verifica si es un comodín
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

    // Si llegamos aquí, significa que no se encontró ningún comodín

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
    std::string** taulaMostrar = new std::string*[nRow];  // Declara un arreglo de punteros a filas

    for (int i = 0; i < nRow; i++) {
        taulaMostrar[i] = new std::string[nCol];  // Crea cada fila con un arreglo de columnas
    }

    for (int i = 0; i < nCol; i++) {
        node* actual = taula[i];  // Inicio de la fila
        int cont=0;
        while (actual != nullptr) {
            // Accede al contenido del nodo actual
            Element* contenido = actual->contigut;
            // Realiza operaciones con el contenido si es necesario
            taulaMostrar[cont][i] = contenido->getSimbol();

            actual = actual->seguent;  // Avanza al siguiente nodo en la fila
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






