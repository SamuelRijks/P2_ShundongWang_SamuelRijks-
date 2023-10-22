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
