#include "LocalVarDefineCommand.h"
#include "../ex1Expressions.h"

void LocalVarDefineCommand::init(vector<string> &origLexer, int index) {
    // init for var x = 2
    name = origLexer.at(index + 2);// at 1 there is a =
    value = Interpreter::getDoubleFromExpression(origLexer.at(index + 3));
}

void LocalVarDefineCommand::execute() {
    //make new variable to put to map
    Variable variable(name, value, Local, "");
    SymbolTable::Instance()->updateVarToSymTMap(variable);
}