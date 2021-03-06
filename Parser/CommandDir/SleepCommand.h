#ifndef FLIGHT_SIM1_SLEEPCOMMAND_H
#define FLIGHT_SIM1_SLEEPCOMMAND_H

#include "FuncCommand.h"
#include <iostream>
#include <unistd.h>
#include <thread>
#include "../ex1Expressions.h"

class SleepCommand : public FuncCommand {
public:
    SleepCommand() {
        numberOfParameters = 1;
    }

    virtual void execute();
};

#endif //FLIGHT_SIM1_SLEEPCOMMAND_H
