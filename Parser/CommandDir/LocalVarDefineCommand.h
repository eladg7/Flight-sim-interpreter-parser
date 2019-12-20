//
// Created by yekaterina on 20/12/2019.
//

#ifndef FLIGHT_SIM1_LOCALVARDEFINECOMMAND_H
#define FLIGHT_SIM1_LOCALVARDEFINECOMMAND_H


#include "VarDefineCommand.h"
#include "../Variable.h"

class LocalVarDefineCommand: public Command {
private:
    string name;
    double value;
public:
    LocalVarDefineCommand(){
        numberOfParameters=3;
    }
    ~LocalVarDefineCommand(){}

    virtual void init(vector<string> &origLexer, int index);
    virtual void execute();

};


#endif //FLIGHT_SIM1_LOCALVARDEFINECOMMAND_H
