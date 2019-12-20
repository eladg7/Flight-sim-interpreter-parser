#include "ConditionCommand.h"

void ConditionCommand::init(vector<string> &origLexer, int index) {
    int loopLimit = origLexer.size() - index;
    for (int i = 1; i < loopLimit; i++) {
        string parm = origLexer.at(index + i);
        if (parm == "}" || (parm.find("}") != std::string::npos)) {
            this->numberOfParameters = i - 1;
            if (parm.length() > 1) {
                //  remove '}'
                parm.pop_back();
                updateParam(parm);
                commandLexer.push_back(parm);
            }
            break;
        }
        updateParam(parm);
        commandLexer.push_back(parm);
    }

    initConditionAndScope();
}

void ConditionCommand::initConditionAndScope() throw(invalid_argument) {
    if (commandLexer.size() > 0) {
        this->condition = commandLexer.at(0);
    } else {
        throw invalid_argument("Invalid condition argument - there's no condition");
    }

    if (commandLexer.size() > 1) {
        //  copy the scope without the condition
        this->scope.assign(commandLexer.begin() + 1, commandLexer.end());
    }
}

void ConditionCommand::updateParam(string &parm) {
    if (Lexer::isCharInString(parm, '"')) {
        Lexer::eraseAllSubStr(parm, "\"");
    } else {
        parm = to_string(getDoubleFromExpression(parm));
    }
}