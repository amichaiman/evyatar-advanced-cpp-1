//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_DEFENSEOBJ_H
#define EVYATAR_CPP_1_DEFENSEOBJ_H


#include "SimObj.h"

class DefenseObj : public SimObj{
public:
    DefenseObj(int dimension);
    virtual char getInitial()=0;
    void print();
};


#endif //EVYATAR_CPP_1_DEFENSEOBJ_H
