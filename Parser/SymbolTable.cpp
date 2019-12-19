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

double SymbolTable::getFromMap(const string &str) {
    mutex_lock.lock();


    mutex_lock.unlock();
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