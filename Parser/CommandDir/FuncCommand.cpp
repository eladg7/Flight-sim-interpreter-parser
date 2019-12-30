#include "FuncCommand.h"

void FuncCommand::init(vector<string> &origLexer, unsigned int index) {
    //  clear arguments so next time we call init it won't push the arguments after the previously pushed arguments
    commandLexer.clear();
    for (int i = 1; i <= numberOfParameters; i++) {
        string parm = origLexer.at(index + i);
        commandLexer.push_back(parm);
    }
}