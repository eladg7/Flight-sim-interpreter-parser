#include "ConditionCommand.h"

void ConditionCommand::init(vector<string> &origLexer, int index) {
    commandLexer.clear();
    bool firstRun = true;
    unsigned int loopLimit = origLexer.size() - index;
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
        if (parm == "}" || (parm.find('}') != std::string::npos)) {
            this->numberOfParameters = i - 1;
            if (parm.length() > 1) {
                //  remove '}'
                parm.pop_back();
                commandLexer.push_back(parm);
            }
            break;
        }
        commandLexer.push_back(parm);
    }

    initConditionAndScope();
}

void ConditionCommand::updateCondition() {
    if (this->condition != nullptr) {
        delete this->condition;
    }
    this->condition = Interpreter::getBooleanCondition(commandLexer.at(0));
}

void ConditionCommand::initConditionAndScope() {
    if (!commandLexer.empty()) {
        this->condition = Interpreter::getBooleanCondition(commandLexer.at(0));
    } else {
        throw invalid_argument("Invalid condition argument - there's no condition");
    }

    if (commandLexer.size() > 1) {
        //  copy the scope without the condition
        this->scope.assign(commandLexer.begin() + 1, commandLexer.end());
    }
}