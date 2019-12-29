#include "PrintCommand.h"
#include "../../Lexer/Lexer.h"

void PrintCommand::execute() {
    //  the argument might be a variable, update it to get the value
    string msg = updateArgument();
    if (Lexer::isCharInString(msg, '"')) {
        Lexer::eraseAllSubStr(msg, "\"");
    }

    if (msg == "done") { //quit server and client.
        client->turnOffRunningMode();
        server->turnOffRunningMode();
    }

    if (!msg.empty()) {
        cout << msg << endl;
    }
}

string PrintCommand::updateArgument() {
    string temp = commandLexer.at(0);
    if (Lexer::isCharInString(temp, '"')) {
        Lexer::eraseAllSubStr(temp, "\"");
    } else {
        temp = to_string(Interpreter::getDoubleFromExpression(temp));
    }
    return temp;
}