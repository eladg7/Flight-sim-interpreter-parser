#include "PrintCommand.h"
#include "../../Lexer/Lexer.h"

void PrintCommand::execute() {

    string msg = commandLexer.at(0);
    if(Lexer::isCharInString(msg, '"')){
        Lexer::eraseAllSubStr(msg,"\"");
    }

    if(msg == "done"){ //quit server and client.
        client->turnOffRunningMode();
        server->turnOffRunningMode();
    }

    if (!msg.empty()) {
        cout << msg << endl;
    }
}