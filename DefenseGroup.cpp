//
// Created by amichai on 29/03/19.
//

#include "DefenseGroup.h"
#include "Tackle.h"
#include "Linebacker.h"
#include "Cornerback.h"
#include "OffenseGroup.h"
#include <iostream>
#include <random>

void DefenseGroup::initialize(int dimension, int num_tackle, int num_linebacker, int num_cornerback) {
    DefenseObj* defense_obj;
    for (int i=0; i<num_tackle; i++) {
        defense_obj = new Tackle(dimension);
        defense_obj->fill_with_random(dimension);
        defense_group.push_back(defense_obj);
        predecessor_count.push_back(1);
    }
    for (int i=0; i<num_linebacker; i++) {
        defense_obj = new Linebacker(dimension);
        defense_obj->fill_with_random(dimension);
        defense_group.push_back(defense_obj);
        predecessor_count.push_back(1);
    }
    for (int i=0; i<num_cornerback; i++) {
        defense_obj = new Cornerback(dimension);
        defense_obj->fill_with_random(dimension);
        defense_group.push_back(defense_obj);
        predecessor_count.push_back(1);
    }
}

void DefenseGroup::print() {
    for (auto obj : defense_group) {
        obj->print();
    }
}

int DefenseGroup::update_strength(OffenseGroup &offense_group) {
    int max_strength = 0;
    for (auto defense_obj : defense_group) {
        defense_obj->compute_strength(offense_group);
        if (defense_obj->get_strength() > max_strength) {
            max_strength = defense_obj->get_strength();
        }
    }
    return max_strength;
}
int DefenseGroup::get_dimestion() {
    return defense_group.at(0)->size();
}
/* returns true if goal was reached */
bool DefenseGroup::update(OffenseGroup &offense_group) {
    /* compute strength for each defense obj */
    if (update_strength(offense_group) == get_dimestion()) {
        return true;
    }
    /* TODO: if strength of one of the defense objects is dimension (which means it's exactly the same. stop*/

    /* choose two random defense objs and perform exchange, then delete 2 weakest */
    exchange();
    delete_weakest();
    delete_weakest();

    /* update individuals */
    for (auto defense_obj : defense_group) {
        defense_obj->mutate();
    }
    return false;
}

void DefenseGroup::put_unique_random(unsigned long a, unsigned long b, unsigned long  min, unsigned long max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type>
            dist(min, max);

    a = static_cast<int>(dist(rng));
    while (a == b) {
        b = static_cast<int>(dist(rng));
    }
}
void DefenseGroup::exchange() {
    /* generate 2 random unique indexes in defense group */
    unsigned long index_a=0, index_b=0;
    put_unique_random(index_a, index_b, 0, defense_group.size() - 1);
    predecessor_count.at(index_a)++;
    predecessor_count.at(index_b)++;

    /* create clone of each */
    DefenseObj *a = defense_group.at(index_a)->clone();
    DefenseObj *b = defense_group.at(index_a)->clone();

    /* perform exchange */
    /* generate 2 random unique indexes in clones */
    put_unique_random(index_a, index_b, 0, static_cast<unsigned long>(a->size() - 1));
    if (b > a) {
        swap(a, b);
    }

    for (unsigned long i=index_a; i < index_b; i++) {
        bool temp = a->get(i);
        a->set(i, b->get(i));
        b->set(i, temp);
    }
    defense_group.push_back(a);
    defense_group.push_back(b);
}

void DefenseGroup::delete_weakest() {
    int strength_of_weakest = defense_group.at(0)->get_strength();
    vector<DefenseObj*>::iterator weakest = defense_group.begin();

    /* find weakest between the defense objects. don't check new object added in exchange */
    for (unsigned long i=1; i<defense_group.size()-2; i++) {
        if (defense_group.at(i)->get_strength() < strength_of_weakest) {
            weakest = defense_group.begin()+i;
        }
    }
    predecessor_count.at(static_cast<unsigned long>(weakest - defense_group.begin()))--;
    defense_group.erase(weakest);
}

