//
// Created by amichai on 29/03/19.
//

#include "Linebacker.h"

Linebacker::Linebacker(int dimension) : DefenseObj(dimension) {
}

char Linebacker::getInitial() const {
    return 'L';
}

DefenseObj* Linebacker::clone() const {
    DefenseObj* linebacker_clone = new Linebacker(size());
    for (unsigned long i=0; i<size(); i++) {
        linebacker_clone->set(i, get(i));
    }
    return linebacker_clone;
}
