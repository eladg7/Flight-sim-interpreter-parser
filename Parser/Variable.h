//
// Created by yekaterina on 19/12/2019.
//

#ifndef FLIGHT_SIM1_VARIABLE_H
#define FLIGHT_SIM1_VARIABLE_H
using namespace std;

#include <string>
#include "Expression.h"

enum Interaction {
    FromSim, ToSim, Local
};

class Variable : public Expression {
private:
    string name;
    double value;
    Interaction inter = Local;
    string simPath = "";

public:
    Variable() {}

    Variable(const string &s, double val);

    Variable(const string &s, double val,
             Interaction interaction, const string &simString);

    Interaction getInteraction() { return inter; }

    string getSim() { return simPath; }

    double getValue() { return value; }

    string getName(){return name;}

    void setValue(double v) { value = v; }

    Variable &operator++();

    Variable &operator++(int);

    Variable &operator--();

    Variable &operator--(int);

    Variable &operator+=(double num);

    Variable &operator-=(double num);

    double calculate() override;

    ~Variable() {}

};


#endif //FLIGHT_SIM1_VARIABLE_H
