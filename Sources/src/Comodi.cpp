
#include "../../Headers/include/Comodi.h"

Comodi::Comodi() : Element('*'){
    this->premi = 0;
}

Comodi::Comodi(int premi, char simbol) : Element(simbol) {
    this->premi = premi;
}

int Comodi::getPremi() {
    return premi;
}

char Comodi::getSimbol() {
    return Element::getSimbol();
}

bool Comodi::operator==(Element *other) {
    // Verifica si 'other' es de tipo Comodi
    Comodi* otherComodi = dynamic_cast<Comodi*>(other);
    return (otherComodi != nullptr);
}

bool Comodi::operator!=(Element *other) {
    // Verifica si 'other' no es de tipo Comodi
    Comodi* otherComodi = dynamic_cast<Comodi*>(other);
    return (otherComodi == nullptr);
}

void Comodi::mostrar() {
    std::cout << getSimbol();
}