//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_SIMULATION_H
#define EVYATAR_CPP_1_SIMULATION_H
#include <iostream>
#include "DefenseGroup.h"
#include "OffenseGroup.h"

using namespace std;

class Simulation {

public:
    void load(char *config_filename, char *offense_filename);
    void start();

    struct InvalidFilesException : public exception {
        virtual const char* what() const throw() override {
            return "Error: Invalid input.";
        }
    };
private:
    int num_iterations{};
    DefenseGroup defense_group;
    OffenseGroup offense_group;
};


#endif //EVYATAR_CPP_1_SIMULATION_H
