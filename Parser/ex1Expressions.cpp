#include "ex1Expressions.h"


regex doubleNumberRegex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
regex variableRegex("^([a-zA-Z]+)([a-zA-Z0-9_]*)$");
map<string, int> operatorPrecedence = {{"+", 1},
                                       {"-", 1},
                                       {"*", 2},
                                       {"/", 2}};


double Value::calculate() {
    return this->num;
}

Value::Value(const double number) {
    this->num = number;
}

Expression *BinaryOperator::getLeft() {
    return this->left;
}

Expression *BinaryOperator::getRight() {
    return this->right;
}

BinaryOperator::~BinaryOperator() {
    delete this->left;
    delete this->right;
}

Plus::Plus(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Plus::calculate() {
    return (this->getLeft()->calculate() + this->getRight()->calculate());
}

Minus::Minus(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Minus::calculate() {
    return (this->getLeft()->calculate() - this->getRight()->calculate());
}

Mul::Mul(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Mul::calculate() {
    return (this->getLeft()->calculate() * this->getRight()->calculate());
}

Div::Div(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Div::calculate() {
    if (abs(this->getRight()->calculate()) < 0.0001) {
        throw "Divide by 0";
    }
    return (this->getLeft()->calculate() / this->getRight()->calculate());
}

UnaryOperator::~UnaryOperator() {
    delete this->exp;
}

Expression *UnaryOperator::getExp() {
    return this->exp;
}

UPlus::UPlus(Expression *e) {
    this->exp = e;
}

double UPlus::calculate() {
    double val = this->getExp()->calculate();
    return val;
}

UMinus::UMinus(Expression *e) {
    this->exp = e;
}

double UMinus::calculate() {
    double val = this->getExp()->calculate();
    return val * (-1);
}

BooleanOperator::~BooleanOperator() {
    delete this->left;
    delete this->right;
}

Expression *BooleanOperator::getLeft() {
    return this->left;
}

Expression *BooleanOperator::getRight() {
    return this->right;
}

GreaterOperator::GreaterOperator(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}

double GreaterOperator::calculate() {
    return isgreater(left->calculate(), right->calculate());
}

GreaterEqualOperator::GreaterEqualOperator(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}

double GreaterEqualOperator::calculate() {
    double leftSide = left->calculate();
    double rightSide = right->calculate();
    return isgreaterequal(leftSide, rightSide);
}

BelowOperator::BelowOperator(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}

double BelowOperator::calculate() {
    return isless(left->calculate(), right->calculate());
}

BelowEqualOperator::BelowEqualOperator(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}

double BelowEqualOperator::calculate() {
    double leftSide = left->calculate();
    double rightSide = right->calculate();
    return islessequal(leftSide, rightSide);
}

EqualOperator::EqualOperator(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}

double EqualOperator::calculate() {
    double leftSide = this->left->calculate();
    double rightSide = this->right->calculate();
    return isgreaterequal(leftSide, rightSide) && islessequal(leftSide, rightSide);
}

NotEqualOperator::NotEqualOperator(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}

double NotEqualOperator::calculate() {
    double leftSide = this->left->calculate();
    double rightSide = this->right->calculate();
    return isless(leftSide, rightSide) || isless(rightSide, leftSide);
}

//stackoverflow
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Expression *Interpreter::interpret(const string &exp) {
    queue<string> polish = getReversePolish(exp);
    stack<Expression *> expressionStack;
    int len = polish.size();
    for (int i = 0; i < len; i++) {
        string front = polish.front();
        if (isOperator(front)) {
            string oper = polish.front();
            polish.pop();

            if (expressionStack.empty()) {
                throw "Missing expressions.";
            }
            Expression *exp1 = expressionStack.top();
            expressionStack.pop();
            if (expressionStack.empty()) {
                throw "Missing expressions.";
            }
            Expression *exp2 = expressionStack.top();
            expressionStack.pop();

            if (oper == "+") {
                expressionStack.push(new Plus(exp1, exp2));
            } else if (oper == "-") {
                expressionStack.push(new Minus(exp2, exp1));
            } else if (oper == "*") {
                expressionStack.push(new Mul(exp1, exp2));
            } else {
                expressionStack.push(new Div(exp2, exp1));
            }
        } else {
            if (isVariable(front)) {
                expressionStack.push(getVariableFromMap(front));
                polish.pop();
            } else if (regex_match(front, doubleNumberRegex)) {
                expressionStack.push(new Value(stod(front)));
                polish.pop();
            } else {
                strcpy(this->excep, "Not a value nor a number nor a operator inserted in string: ");
                strcat(this->excep, front.c_str());
                throw this->excep;
            }
        }
    }
    if (expressionStack.size() > 1 || expressionStack.empty()) {
        throw "Missing expressions.";
    }
    return expressionStack.top();
}


Variable *Interpreter::getVariableFromMap(const string &key) {
    Variable v = SymbolTable::Instance()->getVarFromMap(key);
    return new Variable(v.getName(), v.getValue(), v.getInteraction(), v.getSim());
}


queue<string> Interpreter::getReversePolish(const string &str) {
    queue<string> outputQueue;
    stack<string> operatorStack;
    vector<char> numberVector;
    vector<char> variableVector;
    int countOpenParenthesis = 0;
    char last[2] = {0};

    for (int i = 0; i < str.size(); i++) {
        char token[2] = {0}; //More room for \0
        token[0] = str.at(i);
        if (variableVector.empty() &&
            (isdigit(token[0]) || token[0] == '.'))
            // if the number is not from the variable reading.
        {
            numberVector.push_back(token[0]);
        } else {
            if (!numberVector.empty()) {
                // finished reading number from string
                char number[10] = {0};
                strncpy(number, &numberVector[0], numberVector.size());
                if (!regex_match(number, doubleNumberRegex)) {
                    strcpy(this->excep, "Character is not number double: ");
                    strcat(this->excep, number);
                    throw this->excep;
                }
                outputQueue.push(number);
                numberVector.clear();

            }
            if (!variableVector.empty() && (isOperator(token) || token[0] == ')')) {
                //finished reading all variable
                char var[30] = {0};
                strncpy(var, &variableVector[0], variableVector.size());
                if (isVariable(var)) {
                    outputQueue.push(var);
                } else {
                    strcpy(this->excep, "Not a variable: ");
                    strcat(this->excep, var);
                    throw this->excep;
                }
                variableVector.clear();
            }

            //checking the current token
            if (isOperator(token)) {
                operatorTokenCase(operatorStack, outputQueue, token, i, last);

            } else if (token[0] == '(') {
                countOpenParenthesis++;
                operatorStack.push(token);

            } else if (token[0] == ')') {
                closedParenthesisTokenCase(operatorStack, outputQueue, countOpenParenthesis);

            } else {
                // not an operator or a number, possible variable
                variableVector.push_back(token[0]);
            }
        }
        strcpy(last, token);
    } //stopped reading.

    if (countOpenParenthesis > 0) {//more open than closed Parenthesis.
        throw "There is more open parenthesis then closed ones.";
    }

    if (!numberVector.empty()) {
        // finished reading number from string
        char number[10] = {0};
        strncpy(number, &numberVector[0], numberVector.size());
        if (!regex_match(number, doubleNumberRegex)) {
            strcpy(this->excep, "Character is not number double: ");
            strcat(this->excep, number);
            throw this->excep;
        }
        outputQueue.push(number);
        numberVector.clear();
    }

    if (!variableVector.empty()) { //finished reading variable
        char var[30] = {0};
        strncpy(var, &variableVector[0], variableVector.size());
        if (isVariable(var)) {
            outputQueue.push(var);
        } else {
            strcpy(this->excep, "Not a variable: ");
            strcat(this->excep, var);
            throw this->excep;
        }
        variableVector.clear();
    }

    while (!operatorStack.empty()) {
        outputQueue.push(operatorStack.top());
        operatorStack.pop();
    }
    return outputQueue;
}


void Interpreter::operatorTokenCase(stack<string> &operatorStack, queue<string> &outputQueue, char *token, int loopNum,
                                    char *lastToken) {
    if (strcmp(token, "-") == 0 || strcmp(token, "+") == 0) { // unary operator check.
        if (loopNum == 0 || strcmp(lastToken, "(") == 0 ||
            isOperator(lastToken)) { // before operator no number/variable, or just nothing(i=0)>unary
            outputQueue.push("0");
            operatorStack.push(token);
            strcpy(lastToken, token);
            return;
        }
    }
    if (!operatorStack.empty()) { // binary operator.
        if (operatorPrecedence[operatorStack.top()] >= operatorPrecedence[token]) {
            outputQueue.push(operatorStack.top());
            operatorStack.pop();
        }
    }
    operatorStack.push(token);

}

void Interpreter::closedParenthesisTokenCase(stack<string> &operatorStack, queue<string> &outputQueue,
                                             int &countOpenParenthesis) {
    if (operatorStack.empty()) {
        throw "There is more close parenthesis then open ones.";
    }
    while (operatorStack.top() != "(") {
        outputQueue.push(operatorStack.top());
        operatorStack.pop();
        if (operatorStack.empty()) {
            throw "There is more close parenthesis then open ones.";
        }
    }
    operatorStack.pop(); // pop "(" OpenParenthesis
    countOpenParenthesis--;
}

bool Interpreter::isOperator(const string &s) {
    return s == "-" || s == "+" ||
           s == "*" || s == "/";
}

bool Interpreter::isVariable(const string &s) {
    return SymbolTable::Instance()->isInMap(s);
}

BooleanOperator *Interpreter::getBooleanOperator(string expressionString, Expression *left, Expression *right) {
    BooleanOperator *booleanOperator;
    if (expressionString.find(">=") != string::npos) {
        booleanOperator = new GreaterEqualOperator(left, right);
    } else if (expressionString.find('>') != string::npos) {
        booleanOperator = new GreaterOperator(left, right);
    } else if (expressionString.find("<=") != string::npos) {
        booleanOperator = new BelowEqualOperator(left, right);
    } else if (expressionString.find('<') != string::npos) {
        booleanOperator = new BelowOperator(left, right);
    } else if (expressionString.find("==") != string::npos) {
        booleanOperator = new EqualOperator(left, right);
    } else {
        //   it must be '!='
        booleanOperator = new NotEqualOperator(left, right);
    }

    return booleanOperator;
}

BooleanOperator *Interpreter::getBooleanCondition(string parm) {
    Interpreter interpreter;
    Lexer::eraseAllSubStr(parm, " ");
    vector<string> operatorArguments = isBooleanOperator(parm);
    Expression *left = interpreter.interpret(operatorArguments.at(0));
    Expression *right = interpreter.interpret(operatorArguments.at(1));
    BooleanOperator *op = getBooleanOperator(parm, left, right);
    return op;
}

double Interpreter::getDoubleFromExpression(string parm) {
    Interpreter interpreter;
    double value = 0;
    Lexer::eraseAllSubStr(parm, " ");
    try {
        Expression *e = interpreter.interpret(parm);
        value = e->calculate();
        delete e;
    } catch (const char *&exep) {
        cout << " Error calculating value of " + parm
                + " :" + exep << endl;
    }


    return value;
}