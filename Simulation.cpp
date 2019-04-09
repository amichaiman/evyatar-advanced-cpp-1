//
// Created by amichai on 29/03/19.
//

#include "Simulation.h"
#include <fstream>

void Simulation::load(char *config_filename, char *offense_filename) {
    ifstream config_file = ifstream(config_filename);
    ifstream offense_file = ifstream(offense_filename);

    if (!config_file.is_open() || !offense_file.is_open()) {
        throw InvalidFilesException();
    }
    int dimension;
    int num_tackle;
    int num_linebacker;
    int num_cornerback;

    config_file >> dimension;
    config_file >> num_tackle;
    config_file >> num_linebacker;
    config_file >> num_cornerback;
    config_file >> num_iterations;

    if (config_file.bad() || config_file.fail()) {
        throw InvalidFilesException();
    }

    defense_group.initialize(dimension, num_tackle, num_linebacker, num_cornerback);
    try {
        offense_group.initialize(dimension, offense_file);
    } catch (exception &e) {
        throw InvalidFilesException();
    }
}

void Simulation::start() {
    for (int i=0; i<num_iterations && !defense_group.update(offense_group); i++) {
    }
}
