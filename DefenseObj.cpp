//
// Created by amichai on 29/03/19.
//

#include "DefenseObj.h"
#include <random>
#include <iostream>

DefenseObj::DefenseObj(int dimension) : SimObj(dimension){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,1);
    for (int i=0; i<dimension; i++) {
        SimObj::set(i, static_cast<bool>(dist(rng)));
    }
}

void DefenseObj::print() {
    SimObj::print();
    cout << getInitial();
    cout << endl;
}
