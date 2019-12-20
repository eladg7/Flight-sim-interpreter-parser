//
// Created by yekaterina on 19/12/2019.
//

#include "Variable.h"

Variable::Variable(const string &s, double val) {
    name = s;
    value = val;
}

Variable::Variable(const string &s, double val,
                   Interaction interaction, const string &simString) {
    name = s;
    value = val;
    inter = interaction;
    simPath = simString;
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
    return this->getValue();
}