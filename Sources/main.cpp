#include <iostream>
#include "../Headers/include/Lletra.h"

#include "../Sources/src/Lletra.cpp"
#include "../Sources/src/Element.cpp"
#include "../Sources/src/Comodi.cpp"
#include "../Sources/src/Seleccio.cpp"
#include "../Sources/src/Contenidor.cpp"


int main() {
    int nivelDificultad;

    // Muestra el menú de selección del nivel de dificultad
    std::cout << "Escoge el nivel de dificultad:" << std::endl;
    std::cout << "1. Fácil" << std::endl;
    std::cout << "2. Medio" << std::endl;
    std::cout << "3. Difícil" << std::endl;
    std::cin >> nivelDificultad;


    int nFilas, nColumnas;

    // Determina las dimensiones de la matriz según la elección del usuario
    switch (nivelDificultad) {
        case 1:
            nFilas = 4;
            nColumnas = 6;
            break;
        case 2:
            nFilas = 6;
            nColumnas = 4;
            break;
        case 3:
            nFilas = 8;
            nColumnas = 3;
            break;
        default:
            std::cout << "Opción no válida. Selecciona 1, 2 o 3." << std::endl;
            return 1;
    }

    Contenidor* contenidor = new Contenidor(nFilas, nColumnas);

}