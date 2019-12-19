//
// Created by yekaterina on 19/12/2019.
//

#ifndef FLIGHT_SIM1_EXPRESSION_H
using namespace std;
/**
 * Expression Interface
 */
class Expression {

public:
    virtual double calculate() = 0;
    virtual ~Expression() {}
};
#define FLIGHT_SIM1_EXPRESSION_H

#endif //FLIGHT_SIM1_EXPRESSION_H
