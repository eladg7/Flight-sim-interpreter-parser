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
private:
    SymbolTable() = default;

    ~SymbolTable() = default;

    static SymbolTable *mInstance;
    map<string, double> symT;
  
    mutex mutex_lock;
public:
    static SymbolTable *Instance();

    void addToSimMap(char *buffer, int size);

    double getFromMap(const string &str);
};


#endif //FLIGHT_SIM1_SYMBOLTABLE_H
