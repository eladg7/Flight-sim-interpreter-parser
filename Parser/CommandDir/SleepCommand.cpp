#include "SleepCommand.h"
#include "../ex1Expressions.h"

void SleepCommand::execute() {
    try {
        string temp = commandLexer.at(0);
        int sleepDuration = (int) getDoubleFromExpression(temp);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
    } catch (...) {
        cerr << "Could not parse 'Sleep' duration" << endl;
    }
}