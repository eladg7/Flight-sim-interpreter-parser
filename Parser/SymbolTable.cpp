//
// Created by yekaterina on 16/12/2019.
//

#include "SymbolTable.h"


void SymbolTable::addToSimMap(char *buffer, int size) {
    mutex_lock.lock();
    vector<string> values = Lexer::split(buffer, ',');


    mutex_lock.unlock();
}

double SymbolTable::getFromMap(string str) {
    mutex_lock.lock();


    mutex_lock.unlock();
}