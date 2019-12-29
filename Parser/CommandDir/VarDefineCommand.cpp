#include "VarDefineCommand.h"
#include "LocalVarDefineCommand.h"
#include "SimVarDefineCommand.h"

void VarDefineCommand::init(vector<string> &origLexer, int index) {
    if (origLexer.at(index + 1) == "=") {
        command = new LocalVarDefineCommand();
        command->init(origLexer, index);

    } else {
        command = new SimVarDefineCommand();
        command->init(origLexer, index);
    }
    numberOfParameters=command->getNumberOfParam();
}
void VarDefineCommand::execute() {
    command->execute();
    delete command;
}