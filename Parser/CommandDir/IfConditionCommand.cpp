#include "IfConditionCommand.h"

void IfConditionCommand::execute() {
    updateCondition();
    if (evaluateBooleanOperator(this->condition)) {
        Parser parser(*this->mapCommand);
        parser.parse(this->commandLexer);
    }
}