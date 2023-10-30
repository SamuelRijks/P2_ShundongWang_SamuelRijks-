#include <iostream>
#include "../Headers/include/Lletra.h"
#include "../Headers/include/Contenidor.h"
#include "../Headers/include/Seleccio.h"



int main() {
    int nivelDificultad;

    // Muestra el menú de selección del nivel de dificultad
    std::cout << "Escoge el nivel de dificultad:" << std::endl;
    std::cout << "1. Facil" << std::endl;
    std::cout << "2. Medio" << std::endl;
    std::cout << "3. Dificil" << std::endl;
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
    Seleccio* seleccio = new Seleccio();
    std::cout << "Seleccioneu 3 lletres iguals:" << std::endl;
    seleccio->mostrar();
    std::cout << "" << std::endl;

    std::cout << "Lletres disponibles" << std::endl;
    contenidor->mostrar();




}