//
// Created by samur on 20/10/2023.
//

#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H


#include "Element.h"

class Contenidor {
public:
    Contenidor();
    ~Contenidor();

private:
    struct node{
        Element *contigut;
        node *seguent;
    };

    node *taula;

};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_CONTENIDOR_H
