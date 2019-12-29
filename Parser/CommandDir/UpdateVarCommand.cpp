#include "UpdateVarCommand.h"
#include "../ex1Expressions.h"

void UpdateVarCommand::init(vector<string> &origLexer, int index) {
    // x = 4 is an update
    name = origLexer.at(index + 1);
    string expression = origLexer.at(index + 2);
    newValue = Interpreter::getDoubleFromExpression(expression);
}

void UpdateVarCommand::execute() {

    Variable v = SymbolTable::Instance()->getVarFromMap(name);
    Variable newVar(v.getName(),newValue,v.getInteraction(),v.getSim());
    SymbolTable::Instance()->updateVarToSymTMap(newVar);

    SymbolTable::Instance()->insertMessageToQueue(newVar.getSim(), newValue);
}