//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_TACKLE_H
#define EVYATAR_CPP_1_TACKLE_H


#include "DefenseObj.h"

class Tackle : public DefenseObj {

public:
    Tackle(int dimension);

    DefenseObj *clone() const override;

protected:
    char getInitial() const override;

};


#endif //EVYATAR_CPP_1_TACKLE_H
