//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_DEFENSEGROUP_H
#define EVYATAR_CPP_1_DEFENSEGROUP_H
#include <vector>
#include <random>
#include "DefenseObj.h"
#include "OffenseGroup.h"

using namespace std;

class DefenseGroup {
public:
    void initialize(int dimension, int num_tackle, int num_linebacker, int num_cornerback);
    void print();
    int update_strength(OffenseGroup &group);
    bool update(OffenseGroup &group);

private:
    vector<DefenseObj*> defense_group;
    vector<int> predecessor_count;
    void exchange();
    void put_unique_random(unsigned long a, unsigned long b, unsigned long  min, unsigned long max);

    void delete_weakest();

    int get_dimestion();
};


#endif //EVYATAR_CPP_1_DEFENSEGROUP_H
