#include <iostream>
#include <random>
#include <ctime>
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Error: Invalid input." << endl;
        exit(1);
    }
    srand(static_cast<unsigned int>(time(nullptr)));
    Simulation simulation;
    try {
        simulation.load(argv[1], argv[2]);
    } catch(exception &e) {
        cout << e.what() << endl;
        exit(2);
    }
    simulation.start();
    return 0;
}