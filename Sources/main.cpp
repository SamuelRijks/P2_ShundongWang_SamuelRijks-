#include <iostream>
#include "../Headers/include/Lletra.h"
#include "../Headers/include/Contenidor.h"
#include "../Sources/src/Contenidor.cpp"
#include "../Sources/src/Lletra.cpp"
#include "../Sources/src/Comodi.cpp"
#include "../Sources/src/Seleccio.cpp"
#include "../Sources/src/Element.cpp"


bool SaberEsTerminal();

void MostrarMenuSeleccionDificultad() {
    std::cout << "Escoge el nivel de dificultad:" << std::endl;
    std::cout << "1. Facil" << std::endl;
    std::cout << "2. Medio" << std::endl;
    std::cout << "3. Dificil" << std::endl;
}

void ObtenerDimensionesMatriz(int nivelDificultad, int& nFilas, int& nColumnas) {
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
            throw std::runtime_error("Opción inválida");
    }
}

Element* SeleccionarElemento(Contenidor* contenidor) {
    int numero;
    Element* element = nullptr;

    do {
        do {
            std::cout << "Especifica una columna dins de l´interval [1,6] o 0 per seleccionar l´esteric:"
                      << std::endl;
            std::cin >> numero;
            if (numero < 0 || numero > 6) {
                std::cout
                        << "Número fuera de rango. Debes ingresar un número entre 1 y 6 o 0 para seleccionar el esteric."
                        << std::endl;
            }
        } while (numero < 0 || numero > 7);

        if (numero == 0) {
            try {
                element = contenidor->EliminaComodi();
                // Hacer algo con el comodín encontrado
            } catch (std::runtime_error) {
                std::cout << "No hi han esterics" << std::endl;
                // Manejar la excepción aquí, por ejemplo, mostrar un mensaje de error
            }
        } else {
            element = contenidor->EliminaPerColumna(numero);
        }
    } while (element == nullptr);

    return element;
}

void Juego() {
    int nivelDificultad;
    int nFilas, nColumnas;

    MostrarMenuSeleccionDificultad();
    std::cin >> nivelDificultad;

    ObtenerDimensionesMatriz(nivelDificultad, nFilas, nColumnas);

    Contenidor* contenidor = new Contenidor(nFilas, nColumnas);
    Seleccio* seleccio = new Seleccio();
    bool juegoTerminado = false; // 游戏结束标志

    while (!juegoTerminado) {
        std::cout << "Seleccioneu 3 lletres iguals:" << std::endl;
        seleccio->mostrar();
        std::cout << "" << std::endl;

        std::cout << "Lletres disponibles" << std::endl;
        contenidor->mostrar();

        Element* element = SeleccionarElemento(contenidor);

        std::cout << element->getSimbol() << std::endl;
        seleccio->afegir(element);
        seleccio->eliminar3iguals();
        std::cout << "Lletra seleccionada: " << element->getSimbol() << " punts guanyats " << seleccio->getPremiFinal() << std::endl;

        if (contenidor->getQuants() == 0) {
            std::cout << "se acabó el espacio!" << std::endl;
            std::cout << "Punts total: " << seleccio->getPremiFinal() << std::endl;
            juegoTerminado = true;
        }
        if (seleccio->getPremiFinal() == 4500) {
            std::cout << "s´ha acabat l´espai! " << std::endl;
        }
    }
}

int main() {
    Juego();
    return 0;
}


