//
// Created by amichai on 29/03/19.
//

#ifndef EVYATAR_CPP_1_SIMOBJ_H
#define EVYATAR_CPP_1_SIMOBJ_H
#include <vector>
using namespace std;
class SimObj {
public:
    explicit SimObj(int dimension);

    unsigned long size() const;
    bool get(unsigned long i) const;
    void set(unsigned long i, bool val);
    void print() const;
private:
    vector<bool> v;
};


#endif //EVYATAR_CPP_1_SIMOBJ_H
