//
// Created by samur on 22/10/2023.
//

#ifndef P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H
#define P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H

#include <iostream>
#include "Element.h"


class Lletra : public Element {
private:
    int premi;

public:
    Lletra();
    Lletra(int premi, char simbol);

    int getPremi() override;
    char getSimbol() override;
    bool operator==(Element *other) override;
    bool operator!=(Element *other) override;
};


#endif //P2_SHUNDONGWANG_SAMUELRIJKS_LLETRA_H
