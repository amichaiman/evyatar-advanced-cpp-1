//
// Created by amichai on 29/03/19.
//

#include "Tackle.h"

Tackle::Tackle(int dimension) : DefenseObj(dimension){
}

char Tackle::getInitial() const {
    return 'T';
}

DefenseObj* Tackle::clone() const {
    DefenseObj* tackle_clone = new Tackle(size());
    for (unsigned long i=0; i<size(); i++) {
        tackle_clone->set(i, get(i));
    }
    return tackle_clone;
}
