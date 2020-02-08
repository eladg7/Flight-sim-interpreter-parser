#include "PrintCommand.h"
#include "../../Lexer/Lexer.h"

void PrintCommand::execute() {
    //  the argument might be a variable, update it to get the value
    string msg = updateArgument();
    if (Lexer::isCharInString(msg, '"')) {
        Lexer::eraseAllSubStr(msg, "\"");
    }

    if (!msg.empty()) {
        cout << msg << endl;
    }

    //  check if the message equals to done - and if so stop the server
    auto lowerCaseMsg = msg;
    transform(lowerCaseMsg.begin(), lowerCaseMsg.end(), lowerCaseMsg.begin(),
              [](unsigned char c) { return tolower(c); });

    Lexer::trim(lowerCaseMsg);

    if (lowerCaseMsg == "done") { //quit server and client.
        client->turnOffRunningMode();
        server->turnOffRunningMode();
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