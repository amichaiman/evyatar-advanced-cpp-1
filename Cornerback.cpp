//
// Created by amichai on 29/03/19.
//

#include "Cornerback.h"

Cornerback::Cornerback(int dimension) : DefenseObj(dimension){ }

char Cornerback::getInitial() const {
    return 'C';
}

DefenseObj* Cornerback::clone() const {
    DefenseObj* cornerback_clone = new Cornerback(size());
    for (unsigned long i=0; i<size(); i++) {
        cornerback_clone->set(i, get(i));
    }
    return cornerback_clone;
}
