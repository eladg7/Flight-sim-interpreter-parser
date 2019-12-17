//
// Created by yekaterina on 16/12/2019.
//

#include "SymbolTable.h"
//singeltone

SymbolTable* SymbolTable::mInstance= nullptr;
SymbolTable* SymbolTable::Instance() {
    if(mInstance == nullptr){
        mInstance=new SymbolTable();
    }
    return mInstance;
}


void SymbolTable::addToSimMap(char *buffer, int size) {
    mutex_lock.lock();
    vector<string> values = Lexer::split(buffer, ',');


    mutex_lock.unlock();
}

double SymbolTable::getFromMap(const string &str) {
    mutex_lock.lock();


    mutex_lock.unlock();
}