//
// Created by samur on 20/10/2023.
//

#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_ELEMENT_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_ELEMENT_H
#include <iostream>

class Element {
private:
    char simbol;

public:
    Element() ;
    Element(char simbol);
    virtual char getSimbol() =0;
    virtual int getPremi() =0;
    virtual bool operator==(Element *other) =0;
    virtual bool operator!=(Element *other)=0;
    virtual void mostrar();


};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_ELEMENT_H
