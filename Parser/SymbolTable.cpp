//
// Created by yekaterina on 16/12/2019.
//

#include "SymbolTable.h"
//singeltone

SymbolTable *SymbolTable::mInstance = nullptr;

SymbolTable *SymbolTable::Instance() {
    if (mInstance == nullptr) {
        mInstance = new SymbolTable();
    }
    return mInstance;
}


void SymbolTable::updateSymbolTable() {
    for (map<string, Variable>::iterator it = symT.begin(); it != symT.end(); ++it) {
        if (it->second.getInteraction() == FromSim) { // <-
            if (simMap.find(it->second.getSim()) != simMap.end()) {
                it->second.setValue(simMap[it->second.getSim()]);
            } else {
                cout << "Couldn't find key in simMap" << endl;
            }
        }
    }
}

bool SymbolTable::isInMap(const string &key) {
    mutex_lock.lock();
    bool isIn = true;
    if (symT.find(key) == symT.end()) {
        isIn = false;
    }
    mutex_lock.unlock();
    return isIn;
}


void SymbolTable::updateSimMap(vector<double> values) {
    mutex_lock.lock();
    int valuesIndex = 0;
    for (const string &key:nodesFromSim) {
        simMap[key] = values.at(valuesIndex);
        valuesIndex++;
    }
    updateSymbolTable();

    mutex_lock.unlock();
}

Variable* SymbolTable::getVarFromMap(const string &key) {
    mutex_lock.lock();
    Variable* var = &symT[key];

    mutex_lock.unlock();
    return var;
}