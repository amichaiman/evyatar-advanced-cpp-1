//
// Created by amichai on 29/03/19.
//

#include "DefenseGroup.h"
#include "Tackle.h"
#include "Linebacker.h"
#include "Cornerback.h"
#include <iostream>

void DefenseGroup::initialize(int dimension, int num_tackle, int num_linebacker, int num_cornerback) {
    for (int i=0; i<num_tackle; i++) {
        defense_group.push_back(new Tackle(dimension));
    }
    for (int i=0; i<num_linebacker; i++) {
        defense_group.push_back(new Linebacker(dimension));
    }
    for (int i=0; i<num_cornerback; i++) {
        defense_group.push_back(new Cornerback(dimension));
    }
}

void DefenseGroup::print() {
    for (auto obj : defense_group) {
        obj->print();
    }
}
