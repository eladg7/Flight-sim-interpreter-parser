#ifndef FLIGHT_SIM1_EX1EXPRESSIONS_H
#define FLIGHT_SIM1_EX1EXPRESSIONS_H

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <regex>
#include <queue>
#include <stack>
#include <map>
#include "Variable.h"
#include "SymbolTable.h"
#include "Expression.h"
#include <math.h>

using namespace std;

class Value : public Expression {
    double num;
public:
    explicit Value(const double number);

    double calculate() override;
};

class BinaryOperator : public Expression {
protected:
    Expression *right;
    Expression *left;
public:
    virtual Expression *getLeft();

    virtual Expression *getRight();

    virtual ~BinaryOperator();
};

class Plus : public BinaryOperator {
public:
    Plus(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~Plus() override = default;

};

class Minus : public BinaryOperator {
public:
    Minus(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~Minus() override = default;
};

class Mul : public BinaryOperator {
public:
    Mul(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~Mul() override = default;
};

class Div : public BinaryOperator {
public:
    Div(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~Div() override = default;
};

class UnaryOperator : public Expression {
protected:
    Expression *exp;
public:
    virtual Expression *getExp();

    virtual ~UnaryOperator();
};

class UPlus : public UnaryOperator {
public:
    explicit UPlus(Expression *e);

    double calculate() override;

    ~UPlus() override = default;
};

class UMinus : public UnaryOperator {
public:
    explicit UMinus(Expression *e);

    double calculate() override;

    ~UMinus() override = default;
};

class BooleanOperator : public Expression {
protected:
    Expression *right;
    Expression *left;
public:
    virtual Expression *getLeft();

    virtual Expression *getRight();

    virtual ~BooleanOperator();
};

class GreaterOperator : public BooleanOperator {
public:
    explicit GreaterOperator(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~GreaterOperator() override = default;
};

class GreaterEqualOperator : public BooleanOperator {
public:
    explicit GreaterEqualOperator(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~GreaterEqualOperator() override = default;
};

class BelowOperator : public BooleanOperator {
public:
    explicit BelowOperator(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~BelowOperator() override = default;
};

class BelowEqualOperator : public BooleanOperator {
public:
    explicit BelowEqualOperator(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~BelowEqualOperator() override = default;
};

class EqualOperator : public BooleanOperator {
public:
    explicit EqualOperator(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~EqualOperator() override = default;
};

class NotEqualOperator : public BooleanOperator {
public:
    explicit NotEqualOperator(Expression *leftEX, Expression *rightEX);

    double calculate() override;

    ~NotEqualOperator() override = default;
};

class Interpreter {
private:
    char excep[128];
//    map<string, double> VariableAndValue;
public:

    Expression *interpret(const string &e);

//    void setVariables(const string &e);

    static bool isOperator(const string &s);

    bool isVariable(const string &s);

    queue<string> getReversePolish(const string &str);

    Variable *getVariableFromMap(const string &str);

    void
    closedParenthesisTokenCase(stack<string> &operatorStack, queue<string> &outputQueue, int &countOpenParenthesis);

    void operatorTokenCase(stack<string> &operatorStack, queue<string> &outputQueue, char *token, int loopNum,
                           char *lastToken);

    virtual ~Interpreter() = default;

    static BooleanOperator *getBooleanCondition(string parm);

    static BooleanOperator *getBooleanOperator(string expressionString, Expression *left, Expression *right);

    static double getDoubleFromExpression(string parm);
};

static vector<string> isBooleanOperator(string expression) {
    string pattern("<=|>=|==|!=|<|>");
    regex rx(pattern);

    std::sregex_token_iterator
            first{expression.begin(), expression.end(), rx, -1},
            last;
    return {first, last};
}

static bool evaluateBooleanOperator(BooleanOperator *booleanOperator) {
    return (booleanOperator->calculate());
}

#endif //FLIGHT_SIM1_EX1EXPRESSIONS_H
