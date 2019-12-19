//
// Created by elad on 19/12/2019.
//

#include "FuncCommand.h"

void FuncCommand::init(vector<string> &origLexer, int index) {
    //  clear arguments so next time we call init it won't push the arguments after the previously pushed arguments
    commandLexer.clear();
    for (int i = 1; i <= numberOfParameters; i++) {
        commandLexer.push_back(origLexer.at(index + i));
    }
}