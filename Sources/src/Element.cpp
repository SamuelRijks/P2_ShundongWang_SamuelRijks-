//
// Created by samur on 20/10/2023.
//

char Element::getSimbol() {
    return simbol;
}

int Element::getPremi() {
    return 0;
}

bool Element::operator==(Element *other) {
    return false;
}

bool Element::operator!=(Element *other){
    return true;
}
/*void Element::mostrar() {
    // 在这里实现 Element 类的显示逻辑
    std::cout << "Simbol: " << simbol << " Premi: " << getPremi() << std::endl;
}*/


Element::Element() : simbol('_') {}

Element::Element(char simbol) {}


