//
// Created by elad on 19/12/2019.
//

#include "SleepCommand.h"

void SleepCommand::execute() {
    try {
        int sleepDuration = stoi(commandLexer.at(0));
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
        cout << "finish sleep" << endl;
    } catch (...) {
        cerr << "Could not parse 'Sleep' duration" << endl;
    }
}