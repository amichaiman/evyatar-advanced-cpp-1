//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_DEFENSEOBJ_H
#define EVYATAR_CPP_1_DEFENSEOBJ_H


#include "SimObj.h"
#include "OffenseGroup.h"

class DefenseObj : public SimObj{
public:
    DefenseObj(int dimension);

    void print();

    void compute_strength(OffenseGroup offenseGroup);

    virtual char getInitial() const=0;
    virtual DefenseObj *clone() const=0;
//    virtual double mutation_percentage() const=0;

    void fill_with_random(int dimension);

private:
    int strength; // value between 0 to dimension
    int compute_strength(SimObj *offence_obj);

public:
    int get_strength() const;

    void mutate();
};
#endif //EVYATAR_CPP_1_DEFENSEOBJ_H
