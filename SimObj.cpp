//
// Created by amichai on 29/03/19.
//

#include "SimObj.h"
#include <iostream>

using namespace std;

bool SimObj::get(int i) {
    return v.at(i);
}

void SimObj::set(int i, bool val) {
    v.at(i) = val;
}

void SimObj::print() const {
    for (bool b : v) {
        cout << b << ' ';
    }
}

SimObj::SimObj(int dimension):v(static_cast<unsigned long>(dimension)) {
}
