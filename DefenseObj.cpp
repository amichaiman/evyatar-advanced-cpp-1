//
// Created by amichai on 29/03/19.
//

#include "DefenseObj.h"
#include <random>
#include <iostream>

void DefenseObj::fill_with_random(int dimension){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,1);
    for (int i=0; i<dimension; i++) {
        SimObj::set(i, static_cast<bool>(dist(rng)));
    }
}

DefenseObj::DefenseObj(int dimension) : SimObj(dimension){
}

void DefenseObj::print() {
    SimObj::print();
    cout << getInitial();
    cout << endl;
}

void DefenseObj::compute_strength(OffenseGroup offenseGroup) {
    /* each iteration strength is computed again from zero */
    DefenseObj::strength = 0;
    /* check strength against each offense vector */
    for (auto offense_obj : offenseGroup.get_offense_group()) {
        int strength = compute_strength(offense_obj);
        /* update max strength if necessary */
        if (strength > DefenseObj::strength) {
            DefenseObj::strength = strength;
        }
    }
}

int DefenseObj::compute_strength(SimObj *offence_obj) {
    int strength = 0;
    for (unsigned long i=0; i<size(); i++) {
        if (get(i) == offence_obj->get(i)) {
            strength++;
        }
    }
    return strength;
}

int DefenseObj::get_strength() const {
    return strength;
}

void DefenseObj::mutate() {
    for (unsigned long i=0; i<size(); i++) {
//        if (get_equaly_distibution_in_range(0,1) < mutation_percentage()) {
//            flip(i);
//        }
    }
}

