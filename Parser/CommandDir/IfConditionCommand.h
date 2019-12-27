#ifndef FLIGHT_SIM1_IFCONDITIONCOMMAND_H
#define FLIGHT_SIM1_IFCONDITIONCOMMAND_H

#include "ConditionCommand.h"
#include "../Parser.h"

class IfConditionCommand : public ConditionCommand {
public:
    explicit IfConditionCommand(map<string, Command *> *map) : ConditionCommand(map) {}

    virtual void execute();
};

#endif //FLIGHT_SIM1_IFCONDITIONCOMMAND_H
