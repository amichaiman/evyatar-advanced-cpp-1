//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_LINEBACKER_H
#define EVYATAR_CPP_1_LINEBACKER_H


#include "DefenseObj.h"

class Linebacker : public DefenseObj {

public:
    Linebacker(int dimension);

protected:
    char getInitial() override;
};


#endif //EVYATAR_CPP_1_LINEBACKER_H
