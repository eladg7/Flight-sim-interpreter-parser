#ifndef FLIGHT_SIM1_CONDITIONCOMMAND_H
#define FLIGHT_SIM1_CONDITIONCOMMAND_H

#include "Command.h"
#include "../../Lexer/Lexer.h"
#include "../ex1Expressions.h"
#include "../Parser.h"

using namespace std;

class ConditionCommand : public Command {
protected:
    BooleanOperator *condition = nullptr;

    map<string, Command *> *mapCommand;

    vector<string> scope;

    void updateCondition();

private:
    void updateParam(string &);

    void initConditionAndScope();

public:
    explicit ConditionCommand(map<string, Command *> *mapCommand) {
        this->mapCommand = mapCommand;
    }

    virtual void init(vector<string> &origLexer, int index);

    virtual void execute() = 0;

    virtual ~ConditionCommand() {
        if (this->condition != nullptr) {
            delete this->condition;
        }
    }
};

#endif //FLIGHT_SIM1_CONDITIONCOMMAND_H
