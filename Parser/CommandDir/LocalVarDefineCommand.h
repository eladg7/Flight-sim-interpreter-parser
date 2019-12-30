#ifndef FLIGHT_SIM1_LOCALVARDEFINECOMMAND_H
#define FLIGHT_SIM1_LOCALVARDEFINECOMMAND_H


#include "VarDefineCommand.h"
#include "../Variable.h"

class LocalVarDefineCommand : public Command {
private:
    string name;
    double value;
public:
    LocalVarDefineCommand() {
        numberOfParameters = 3;
    }

    ~LocalVarDefineCommand() {}

    virtual void init(vector<string> &origLexer, unsigned int index);

    virtual void execute();

};


#endif //FLIGHT_SIM1_LOCALVARDEFINECOMMAND_H
