//
// Created by elad on 19/12/2019.
//

#ifndef FLIGHT_SIM1_PRINTCOMMAND_H
#define FLIGHT_SIM1_PRINTCOMMAND_H

#include "FuncCommand.h"
#include <iostream>

using namespace std;
class PrintCommand : public FuncCommand {
public:
    PrintCommand() {
        numberOfParameters = 1;
    }

    virtual void execute();
};

#endif //FLIGHT_SIM1_PRINTCOMMAND_H
