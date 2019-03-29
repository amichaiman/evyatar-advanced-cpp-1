//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_DEFENSEGROUP_H
#define EVYATAR_CPP_1_DEFENSEGROUP_H
#include <vector>
#include "DefenseObj.h"

using namespace std;

class DefenseGroup {

public:
    void initialize(int dimension, int num_tackle, int num_linebacker, int num_cornerback);
    void print();
private:
    vector<DefenseObj*> defense_group;
};


#endif //EVYATAR_CPP_1_DEFENSEGROUP_H
