#ifndef FLIGHT_SIM1_VARDEFINECOMMAND_H
#define FLIGHT_SIM1_VARDEFINECOMMAND_H


#include "Command.h"
#include "LocalVarDefineCommand.h"
#include "SimVarDefineCommand.h"

class VarDefineCommand : public Command{
private:
    Command *command;

public:
    VarDefineCommand(){
        command= nullptr;

    }
    ~VarDefineCommand(){}

    virtual void init(vector<string> &origLexer,unsigned int index);
    virtual void execute();

};


#endif //FLIGHT_SIM1_VARDEFINECOMMAND_H
