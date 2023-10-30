#include <iostream>
#include "../Headers/include/Lletra.h"
#include "../Headers/include/Contenidor.h"
#include "../Headers/include/Seleccio.h"
/*#include "../Sources/src/Contenidor.cpp"
#include "../Sources/src/Lletra.cpp"
#include "../Sources/src/Comodi.cpp"
#include "../Sources/src/Seleccio.cpp"
#include "../Sources/src/Element.cpp"*/



int main() {
    int nivelDificultad;
    int numero;
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
    do {
        std::cout << "Especifica una columna dins de interval [1,6] o 0 per seleccionar esteric:" << std::endl;
        std::cin >> numero;

        if (numero < 0 || numero > 6) {
            std::cout << "Número fuera de rango. Debes ingresar un número entre 1 y 6 o 0 para seleccionar el esteric." << std::endl;
        }
    } while (numero < 0 || numero > 7);

    Element* removedElement = contenidor->EliminaPerColumna(numero);
    contenidor->mostrar();


}