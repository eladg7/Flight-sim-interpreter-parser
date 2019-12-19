#ifndef FLIGHT_SIM1_EXPRESSION_H
#define FLIGHT_SIM1_EXPRESSION_H

class Expression {

public:
    virtual double calculate() = 0;
    virtual ~Expression() {}

//    static double fromStringToDouble(const string &parm){
//        Interpreter interpreter;
//        Expression *e = interpreter.interpret(parm);
//        double value = e->calculate();
//        delete(e);
//        return value;
//    }
};
#endif //FLIGHT_SIM1_EXPRESSION_H
