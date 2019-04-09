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
        /* create single offense object */
        SimObj* simObj = new SimObj(dimension);
        /* fill object with data from offense_file */
        for (int j=0; j<dimension; j++) {
            int val;
            offense_file >> val;
            if (offense_file.bad() || offense_file.fail()) {
                throw exception();
            }
            simObj->set(j, static_cast<bool>(val));
        }
        /* add to group */
        offense_group.push_back(simObj);
    }
}

void OffenseGroup::print() {
    for (auto obj : offense_group) {
        obj->print();
        cout << endl;
    }
}

const vector<SimObj *> &OffenseGroup::get_offense_group() const {
    return offense_group;
}
