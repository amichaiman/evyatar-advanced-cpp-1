//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_CORNERBACK_H
#define EVYATAR_CPP_1_CORNERBACK_H


#include "DefenseObj.h"

class Cornerback : public DefenseObj{
public:
    Cornerback(int dimension);

protected:
    char getInitial() override;
};


#endif //EVYATAR_CPP_1_CORNERBACK_H
