#ifndef FLIGHT_SIM1_GENERICFUNCTIONCOMMAND_H
#define FLIGHT_SIM1_GENERICFUNCTIONCOMMAND_H

#include "FuncCommand.h"
#include "../../Lexer/Lexer.h"
#include "../Parser.h"
#include "../SymbolTable.h"
#include "../Variable.h"

class GenericFunctionCommand : public FuncCommand {
private:
    vector<string> scope;

    Variable *argument = nullptr;

    bool initiated = false;

    bool executeAfterInit = true;

    map<string, Command *> *mapCommand;

    void initArgumentAndScope();

    void initFunction(vector<string> &origLexer, int index);

public :
    explicit GenericFunctionCommand(map<string, Command *> *mapCommand) {
        this->mapCommand = mapCommand;
    }

    virtual void init(vector<string> &origLexer, int index);

    virtual void execute();

    virtual ~GenericFunctionCommand() {
        if (this->argument != nullptr) {
            delete this->argument;
        }
    }
};

#endif //FLIGHT_SIM1_GENERICFUNCTIONCOMMAND_H
