#include "ConditionCommand.h"
#include "../ex1Expressions.h"

void ConditionCommand::init(vector<string> &origLexer, int index) {
    bool firstRun = true;
    int loopLimit = origLexer.size() - index;
    for (int i = 1; i < loopLimit; i++) {
        string parm = origLexer.at(index + i);
        if (firstRun) {
            if (Lexer::isCharInString(parm, '{')) {
                Lexer::eraseAllSubStr(parm, "{");
            }
            Lexer::eraseAllSubStr(parm, " ");
            commandLexer.push_back(parm);
            firstRun = false;
            continue;
        }
        if (parm == "}" || (parm.find("}") != std::string::npos)) {
            this->numberOfParameters = i - 1;
            if (parm.length() > 1) {
                //  remove '}'
                parm.pop_back();
//                updateParam(parm);
                commandLexer.push_back(parm);
            }
            break;
        }
//        updateParam(parm);
        commandLexer.push_back(parm);
    }

    initConditionAndScope();
}

void ConditionCommand::updateCondition() {
    this->condition = getBooleanCondition(commandLexer.at(0));
}

void ConditionCommand::initConditionAndScope() {
    if (commandLexer.size() > 0) {
        this->condition = getBooleanCondition(commandLexer.at(0));
    } else {
        throw invalid_argument("Invalid condition argument - there's no condition");
    }

    if (commandLexer.size() > 1) {
        //  copy the scope without the condition
        this->scope.assign(commandLexer.begin() + 1, commandLexer.end());
    }
}

void ConditionCommand::updateParam(string &parm) {
//    if (Lexer::isCharInString(parm, '"')) {
//        Lexer::eraseAllSubStr(parm, "\"");
//    } else {
    try {
        string temp = to_string(getDoubleFromExpression(parm));
        parm = temp;
    } catch (...) {
        //  it's a funcCommand (i.e. Print Sleep...)

    }
//    }
}