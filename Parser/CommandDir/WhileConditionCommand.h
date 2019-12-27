#ifndef FLIGHT_SIM1_WHILECONDITIONCOMMAND_H
#define FLIGHT_SIM1_WHILECONDITIONCOMMAND_H

#include "ConditionCommand.h"

class WhileConditionCommand : public ConditionCommand {
public:
    explicit WhileConditionCommand(map<string, Command *> *map) : ConditionCommand(map) {}

    virtual void execute();

    virtual ~WhileConditionCommand() {}
};

#endif //FLIGHT_SIM1_WHILECONDITIONCOMMAND_H
