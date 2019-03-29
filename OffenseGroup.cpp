//
// Created by amichai on 29/03/19.
//

#include "OffenseGroup.h"
#include <iostream>

void OffenseGroup::initialize(int dimension, ifstream &offense_file) {
    int size;
    offense_file >> size;

    if (offense_file.bad() || offense_file.fail()) {
        throw exception();
    }
    for (int i=0; i<size; i++) {
        SimObj* simObj = new SimObj(dimension);
        for (int j=0; j<dimension; j++) {
            int val;
            offense_file >> val;
            if (offense_file.bad() || offense_file.fail()) {
                throw exception();
            }
            simObj->set(j, static_cast<bool>(val));
        }
        offense_group.push_back(simObj);
    }
}

void OffenseGroup::print() {
    for (auto obj : offense_group) {
        obj->print();
        cout << endl;
    }
}
