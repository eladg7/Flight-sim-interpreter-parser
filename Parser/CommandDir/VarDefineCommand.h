//
// Created by yekaterina on 20/12/2019.
//

#ifndef FLIGHT_SIM1_VARDEFINECOMMAND_H
#define FLIGHT_SIM1_VARDEFINECOMMAND_H


#include "Command.h"


class VarDefineCommand : public Command{
private:
    Command *command;

public:
    VarDefineCommand(){
        command= nullptr;

    }
    ~VarDefineCommand(){}

    virtual void init(vector<string> &origLexer, int index);
    virtual void execute();

};


#endif //FLIGHT_SIM1_VARDEFINECOMMAND_H
