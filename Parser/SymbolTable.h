//
// Created by yekaterina on 16/12/2019.
//

#ifndef FLIGHT_SIM1_SYMBOLTABLE_H
#define FLIGHT_SIM1_SYMBOLTABLE_H

#include <map>
#include <mutex>
#include "Variable.h"
#include <vector>
#include "../Lexer/Lexer.h"


using namespace std;

class SymbolTable {
    map<string,string> generic_small={
            {"airspeed-indicator_indicated-speed-kt",
             "/instrumentation/airspeed-indicator/indicated-speed-kt"},
            {"altimeter_indicated-altitude-ft",
             "/instrumentation/altimeter/indicated-altitude-ft"},
            {"altimeter_pressure-alt-ft",
             "/instrumentation/altimeter/pressure-alt-ft"},
            {"attitude-indicator_indicated-pitch-deg",
             "/instrumentation/attitude-indicator/indicated-pitch-deg"}
    };
public:
    static map<string, Variable> symT;
    mutex mutex_lock;

    void addToSimMap(char *buffer, int size);

    double getFromMap(string str);
};


#endif //FLIGHT_SIM1_SYMBOLTABLE_H
