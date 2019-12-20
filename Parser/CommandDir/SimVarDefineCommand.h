//
// Created by yekaterina on 20/12/2019.
//

#ifndef FLIGHT_SIM1_SIMVARDEFINECOMMAND_H
#define FLIGHT_SIM1_SIMVARDEFINECOMMAND_H


#include "Command.h"
#include "../Variable.h"

class SimVarDefineCommand: public Command {
private:
    string name;
    double value;
    string simPath;
    Interaction inter;
public:
    SimVarDefineCommand(){
        numberOfParameters=4;
    }
    ~SimVarDefineCommand(){}

    virtual void init(vector<string> &origLexer, int index);
    virtual void execute();

};


#endif //FLIGHT_SIM1_SIMVARDEFINECOMMAND_H
