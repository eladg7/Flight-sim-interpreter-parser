//
// Created by elad on 19/12/2019.
//

#include "PrintCommand.h"
#include "../../Lexer/Lexer.h"

void PrintCommand::execute() {

    string msg = commandLexer.at(0);
    if(Lexer::isCharInString(msg, '"')){
        Lexer::eraseAllSubStr(msg,"\"");
    }

    if(msg == "Done"){
        client->turnOffRunningMode();
        server->turnOffRunningMode();
    }

    if (!msg.empty()) {
        cout << msg << endl;
    }
}