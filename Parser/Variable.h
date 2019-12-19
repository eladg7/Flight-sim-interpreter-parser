//
// Created by yekaterina on 19/12/2019.
//

#ifndef FLIGHT_SIM1_VARIABLE_H
#define FLIGHT_SIM1_VARIABLE_H


#include <string>
#include "Expression.h"

using namespace std;

enum Interaction {
    FromSim, ToSim, Local
};

class Variable : public Expression {
    string name;
    double value;
    Interaction inter=Local;
    string sim="";

public:
    Variable(){}
    Variable(const string &s, double val);

    Variable(const string &s, double val,
             string interaction, const string &simString);

    Interaction getInteraction() { return inter; }

    string getSim() { return sim; }

    void setValue(double v) { value = v; }

    double getValue(){return value;}

    Variable &operator++();

    Variable &operator++(int);

    Variable &operator--();

    Variable &operator--(int);

    Variable &operator+=(double num);

    Variable &operator-=(double num);

    double calculate() override;

    ~Variable(){}

};


#endif //FLIGHT_SIM1_VARIABLE_H
