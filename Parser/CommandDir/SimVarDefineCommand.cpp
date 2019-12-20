//
// Created by yekaterina on 20/12/2019.
//

#include "SimVarDefineCommand.h"
#include "../SymbolTable.h"

void SimVarDefineCommand::init(vector<string> &origLexer, int index) {
    name=origLexer.at(index+1);
    if(origLexer.at(index+2)=="<-"){
        inter =FromSim;
    }else{
        inter=ToSim;
    }
    simPath=origLexer.at(index+4);
    if (Lexer::isCharInString(simPath, '"')) {
        Lexer::eraseAllSubStr(simPath, "\"");
    }
}

void SimVarDefineCommand::execute() {
    Variable v(name,0,inter,simPath);
    SymbolTable::Instance()->updateVarToSymTMap(v);
}