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
    virtual char getSimbol() =0;
    virtual int getPremi() =0;
    virtual bool operator==(Element *other) =0;
    virtual bool operator!=(Element *other)=0;

};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_ELEMENT_H
