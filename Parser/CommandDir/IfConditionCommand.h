//
// Created by elad on 20/12/2019.
//

#ifndef FLIGHT_SIM1_IFCONDITIONCOMMAND_H
#define FLIGHT_SIM1_IFCONDITIONCOMMAND_H

#include "ConditionCommand.h"

class IfConditionCommand : public ConditionCommand {
public:
    virtual void execute();
};

#endif //FLIGHT_SIM1_IFCONDITIONCOMMAND_H
