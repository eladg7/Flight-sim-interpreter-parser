#include "WhileConditionCommand.h"
void WhileConditionCommand::execute() {
    while (evaluateBooleanOperator(this->condition)) {
        Parser parser(*this->mapCommand);
        parser.parse(this->commandLexer);
    }
}