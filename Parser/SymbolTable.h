//
// Created by yekaterina on 16/12/2019.
//

#ifndef FLIGHT_SIM1_SYMBOLTABLE_H
#define FLIGHT_SIM1_SYMBOLTABLE_H

#include <map>
#include <mutex>

using namespace std;

class SymbolTable {
public:
    static map<string, double> symT;
    mutex mutex_lock;

    void addToMap(char *buffer, int size);

    double getFromMap(string str);
};


#endif //FLIGHT_SIM1_SYMBOLTABLE_H
