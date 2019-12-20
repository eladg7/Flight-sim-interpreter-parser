#include "LocalVarDefineCommand.h"
#include "../ex1Expressions.h"

void LocalVarDefineCommand::init(vector<string> &origLexer, int index) {
    name=origLexer.at(index + 2);// at 1 there is a =
    value=getDoubleFromExpression(origLexer.at(index+3));
}

void LocalVarDefineCommand::execute() {
    Variable variable(name,value,Local,"");
    SymbolTable::Instance()->updateVarToSymTMap(variable);
}