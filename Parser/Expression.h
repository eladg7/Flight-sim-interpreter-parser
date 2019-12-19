
#ifndef EX1_EXPRESSION_H
#define EX1_EXPRESSION_H

#include <string>

using namespace std;

/**
 * Expression Interface
 */
class Expression {

public:
    virtual double calculate() = 0;

    virtual ~Expression() {}
};

#endif //EX1_EXPRESSION_H
