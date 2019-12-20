#include "IfConditionCommand.h"

void IfConditionCommand::execute() {
    if (evaluateBooleanOperator(this->condition)) {
        Parser parser(*this->mapCommand);
        parser.parse(this->commandLexer);
    }
}