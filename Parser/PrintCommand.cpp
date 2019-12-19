//
// Created by elad on 19/12/2019.
//

#include "PrintCommand.h"

void PrintCommand::execute() {
    string msg = commandLexer.at(0);
    if (!msg.empty()) {
        cout << msg << endl;
    }
}