//
// Created by yekaterina on 19/12/2019.
//

#include "Variable.h"

Variable::Variable(const string &s, double val){
    name = s;
    value = val;
}
Variable::Variable(const string &s, double val,
                   string interaction, const string &simString) {
    name = s;
    value = val;
    if (interaction == "<-") {
        inter = FromSim;
    } else if (interaction == "->") {
        inter = ToSim;
    } else {
        inter = Local;
    }
    sim = simString;
}

Variable &Variable::operator+=(const double num) {
    this->value = this->value + num;
    return *this;
}

Variable &Variable::operator-=(const double num) {
    this->value = this->value - num;
    return *this;
}

Variable &Variable::operator++() {
    this->value++;
    return *this;
}

Variable &Variable::operator++(int) {
    this->value++;
    return *this;
}

Variable &Variable::operator--() {
    this->value--;
    return *this;
}

Variable &Variable::operator--(int) {
    this->value--;
    return *this;
}

double Variable::calculate() {
    return this->value;
}