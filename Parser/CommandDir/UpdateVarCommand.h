#ifndef FLIGHT_SIM1_UPDATEVARCOMMAND_H
#define FLIGHT_SIM1_UPDATEVARCOMMAND_H


#include "Command.h"

class UpdateVarCommand : public Command{
    string name;
    double newValue;
public:
    UpdateVarCommand(){
        numberOfParameters=2;
    }
    ~UpdateVarCommand(){}

    virtual void init(vector<string> &origLexer,unsigned int index);

    virtual void execute();



};


#endif //FLIGHT_SIM1_UPDATEVARCOMMAND_H
