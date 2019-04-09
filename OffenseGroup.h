//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_OFFENSEGROUP_H
#define EVYATAR_CPP_1_OFFENSEGROUP_H
#include <fstream>
#include <vector>
#include "SimObj.h"

using namespace std;

class OffenseGroup {

public:
    void initialize(int dimension, ifstream &offense_file);

    const vector<SimObj *> &get_offense_group() const;
    void print();

private:
    vector<SimObj*> offense_group;
};


#endif //EVYATAR_CPP_1_OFFENSEGROUP_H
