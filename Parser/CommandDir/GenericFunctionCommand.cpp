#include "GenericFunctionCommand.h"

void GenericFunctionCommand::init(vector<string> &origLexer, int index) {
    if (!this->initiated) {
        initFunction(origLexer, index);
    } else {
        this->argument->setValue(atof(origLexer.at(index + 1).c_str()));
        this->numberOfParameters = 1;
    }
}

void GenericFunctionCommand::initFunction(vector<string> &origLexer, int index) {
    commandLexer.clear();
    bool firstRun = true;
    unsigned int loopLimit = origLexer.size() - index;
    for (int i = 1; i < loopLimit; i++) {
        string parm = origLexer.at(index + i);
        if (firstRun) {
            if (Lexer::isCharInString(parm, '{')) {
                Lexer::eraseAllSubStr(parm, "{");
            }

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
    initArgumentAndScope();
    this->initiated = true;
}

void GenericFunctionCommand::execute() {
    if (this->initiated && !this->executeAfterInit) {
        SymbolTable::Instance()->updateVarToSymTMap(*this->argument);
        Parser parser(*this->mapCommand);
        parser.parse(this->commandLexer);
    } else {
        this->executeAfterInit = false;
    }
}

void GenericFunctionCommand::initArgumentAndScope() {
    if (!commandLexer.empty()) {
        //  remove the var, because all we need is the variable name
        Lexer::eraseAllSubStr(commandLexer.at(0), "var");
        Lexer::trim(commandLexer.at(0));
        this->argument = new Variable(commandLexer.at(0), 0, Local, "");
        SymbolTable::Instance()->updateVarToSymTMap(*this->argument);
    }
    if (commandLexer.size() > 1) {
        //  copy the scope without the condition
        this->scope.assign(commandLexer.begin() + 1, commandLexer.end());
    }
}