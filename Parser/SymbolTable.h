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
#include "xmlReader.h"
#include "ex1Expressions.h"

#define XML_FILE_NAME "generic_small.xml"

using namespace std;

class SymbolTable {
private:
    SymbolTable() = default;

    ~SymbolTable() = default;

    static SymbolTable *mInstance;
    map<string, Variable> symT;

    vector<string> nodesFromSim =
            xmlReader::readXmlFile(XML_FILE_NAME);
    map<string, double> simMap;

    mutex simMapLock;
    mutex symTLock;

public:
    static SymbolTable *Instance();

    void updateSymbolTable();

    Variable* getVarFromMap(const string &key);

    bool isInMap(const string &key);

    void updateSimMap(vector<double> values);

    void addVariableToSymTMap(Variable &v);
};


#endif //FLIGHT_SIM1_SYMBOLTABLE_H
