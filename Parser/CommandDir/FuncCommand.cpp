//
// Created by elad on 19/12/2019.
//

#include "../../Lexer/Lexer.h"
#include "FuncCommand.h"
#include "../ex1Expressions.h"

void FuncCommand::init(vector<string> &origLexer, int index) {
    //  clear arguments so next time we call init it won't push the arguments after the previously pushed arguments
    commandLexer.clear();
    for (int i = 1; i <= numberOfParameters; i++) {
        string parm = origLexer.at(index + i);
        if (Lexer::isCharInString(parm, '"')) {
            Lexer::eraseAllSubStr(parm, "\"");
        } else {
            parm = to_string(getDoubleFromExpression(parm));
        }
        commandLexer.push_back(parm);
    }
}