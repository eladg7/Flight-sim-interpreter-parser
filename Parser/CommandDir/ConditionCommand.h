#ifndef FLIGHT_SIM1_CONDITIONCOMMAND_H
#define FLIGHT_SIM1_CONDITIONCOMMAND_H

#include "Command.h"
#include "../../Lexer/Lexer.h"
#include "../ex1Expressions.h"

using namespace std;

class ConditionCommand : public Command {
protected:
    string condition;
    vector<string> scope;
private:
    void updateParam(string &);

    void initConditionAndScope() throw(invalid_argument);

public:
    virtual void init(vector<string> &origLexer, int index);

    virtual void execute() = 0;

    virtual ~ConditionCommand() {}
};

#endif //FLIGHT_SIM1_CONDITIONCOMMAND_H
