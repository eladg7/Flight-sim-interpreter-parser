//
// Created by yekaterina on 17/12/2019.
//

#ifndef FLIGHT_SIM1_VARIABLE_H
#define FLIGHT_SIM1_VARIABLE_H

using namespace std;
enum Interaction {
    FromSim, ToSim
};// to ->, from <-


class Variable {
private:
    double value;
    string simPath;
    Interaction inter;

public:
    Variable(const string &arrow, double v, const string &sim) {
        if ("->" == arrow) {
            inter = ToSim;
        } else {
            inter = FromSim;
        }
        value = v;
        simPath = sim;
    }

    string getSim() { return simPath; }

    double getValue() { return value; }

    void setValue(double v) { value = v; }

    Interaction getInteraction() { return inter; }

};


#endif //FLIGHT_SIM1_VARIABLE_H
