//
// Created by amichai on 29/03/19.
//

#include "SimObj.h"
#include <iostream>

using namespace std;

bool SimObj::get(unsigned long i) const {
    return v.at(i);
}

void SimObj::set(unsigned long i, bool val) {
    v.at(i) = val;
}

void SimObj::print() const {
    for (bool b : v) {
        cout << b << ' ';
    }
}

SimObj::SimObj(int dimension):v(static_cast<unsigned long>(dimension)) {
}

unsigned long SimObj::size() const {
    return v.size();
}
