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
    symTLock.lock();
    map<string, Variable> tempSymTMap = symT;
    symTLock.unlock();

    simMapLock.lock();
    map<string, double> tempSimMap = simMap;
    simMapLock.unlock();

    for (map<string, Variable>::iterator it = tempSymTMap.begin();
         it != tempSymTMap.end(); ++it) {
        if (it->second.getInteraction() == FromSim) { // <- from sim to
            string simPath = it->second.getSim();
            if (tempSimMap.find(simPath) != tempSimMap.end()) {
                double newValue = tempSimMap[it->second.getSim()];

                symTLock.lock();
                symT[it->first].setValue(newValue);
                symTLock.unlock();

            } else {
                cout << "Couldn't find key in simMap" << endl;
            }
        }
    }
}

bool SymbolTable::isInMap(const string &key) {
    symTLock.lock();
    bool isIn = true;
    if (symT.find(key) == symT.end()) {
        isIn = false;
    }
    symTLock.unlock();
    return isIn;
}


void SymbolTable::updateSimMap(vector<double> values) {
    int valuesIndex = 0;
    for (const string &key:nodesFromSim) {
        if (valuesIndex < values.size()) {
            simMapLock.lock();
            simMap[key] = values.at(valuesIndex);
            simMapLock.unlock();

        } else {
            simMapLock.lock();
            simMap[key] = 0;
            simMapLock.unlock();

        }
        valuesIndex++;
    }
    updateSymbolTable();

}

Variable SymbolTable::getVarFromMap(const string &key) {
    symTLock.lock();
    Variable var = symT[key];
    symTLock.unlock();

    return var;
}

void SymbolTable::updateVarToSymTMap(Variable &v) {
    symTLock.lock();
    symT[v.getName()] = v;
    symTLock.unlock();
}

bool SymbolTable::isQueueEmpty() {
    queueLock.lock();
    bool empty = messageForClient.empty();
    queueLock.unlock();
    return empty;
}

string SymbolTable::getLastMessage() {
    queueLock.lock();
    string message=messageForClient.front();
    messageForClient.pop();
    queueLock.unlock();
    return message;

}

void SymbolTable::insertMessageToQueue(string simPath, double value) {
    string message="set "+simPath +" "+ to_string(value);
    queueLock.lock();
    messageForClient.push(message);
    queueLock.unlock();
}