#ifndef FLIGHT_SIM1_FUNCCOMMAND_H
#define FLIGHT_SIM1_FUNCCOMMAND_H

#include "Command.h"

class FuncCommand : public Command {
public:
    virtual void init(vector<string> &origLexer, unsigned int index);

    virtual void execute() = 0;

    ~FuncCommand() {}
};

#endif //FLIGHT_SIM1_FUNCCOMMAND_H
