#include "VarDefineCommand.h"

void VarDefineCommand::init(vector<string> &origLexer,unsigned int index) {
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