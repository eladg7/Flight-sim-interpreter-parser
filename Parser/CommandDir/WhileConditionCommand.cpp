#include "WhileConditionCommand.h"

void WhileConditionCommand::execute() {
    updateCondition();
    while (evaluateBooleanOperator(this->condition)) {
        Parser parser(*this->mapCommand);
        parser.parse(this->commandLexer);
        updateCondition();
    }
}