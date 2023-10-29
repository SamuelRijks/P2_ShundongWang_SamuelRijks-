#include <iostream>
#include "../Headers/include/Lletra.h"

#include "../Sources/src/Lletra.cpp"
#include "../Sources/src/Element.cpp"
#include "../Sources/src/Comodi.cpp"
#include "../Sources/src/Seleccio.cpp"
#include "../Sources/src/Element.cpp"
int main() {
    std::cout<<"Hello World";

    Lletra c; //invoca el constructor per defecte
    Lletra b(50,'B');

    //Element e; ERROR: no es pot inicialitzar un objecte d'una classe abstracte
    //Element seleccionades[6]; MATEIX ERROR

    Element *e;
    e= new Lletra(50,'A');

    // Element *seleccionades;
    //  seleccionades = new Lletra[6];
    // crea un array del tipus Element però inicialitzem amb el constructor per defecte de la filla Lletra

    Element *seleccionades[6]; // 创建指针数组

    for (int i = 0; i < 6; i++) {
        seleccionades[i] = new Lletra(0, '_'); // 用 Lletra 对象初始化数组
    }

    // 释放动态分配的内存
    for (int i = 0; i < 6; i++) {
        delete seleccionades[i];
    }

    return 0;
}
