#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    int i = 0;

    while (i < line.length()) {
        // skip spaces
        if (isspace(line[i])) {
            i++;
        }
        // read a whole number
        else if (isdigit(line[i])) {
            string num = "";

            while (i < line.length() && isdigit(line[i])) {
                num += line[i];
                i++;
            }

            Token t;
            t.value = num;
            tokens.push_back(t);
        }
        // operators and parentheses
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' ||
                 line[i] == '/' || line[i] == '(' || line[i] == ')') {
            Token t;
            t.value = line[i];
            tokens.push_back(t);
            i++;
                 }
        // invalid character
        else {
            Token t;
            t.value = line[i];
            tokens.push_back(t);
            i++;
        }
    }

    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    if (op == "*" || op == "/") {
        return 2;
    }
    else if (op == "+" || op == "-") {
        return 1;
    }
    return 0;
}
// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    int count = 0;

    if (tokens.empty()) {
        return false;
    }

    for (int i = 0; i < tokens.size(); i++) {
        string val = tokens[i].value;

        if (isdigit(val[0])) {
            count++;
        }
        else if (isOperator(val)) {
            if (count < 2) {
                return false;
            }
            count--;
        }
        else {
            return false;
        }
    }

    return count == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    if (tokens.empty()) {
        return false;
    }

    int parenCount = 0;
    bool expectOperand = true;

    for (int i = 0; i < tokens.size(); i++) {
        string val = tokens[i].value;

        if (expectOperand) {
            if (isdigit(val[0])) {
                expectOperand = false;
            }
            else if (val == "(") {
                parenCount++;
            }
            else {
                return false;
            }
        }
        else {
            if (isOperator(val)) {
                expectOperand = true;
            }
            else if (val == ")") {
                parenCount--;
                if (parenCount < 0) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    // valid infix must end after an operand and all parentheses must close
    return !expectOperand && parenCount == 0;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;

    for (int i = 0; i < tokens.size(); i++) {
        string val = tokens[i].value;

        // if it is a number, push it
        if (isdigit(val[0])) {
            stack.push(stod(val));
        }
        else if (isOperator(val)) {
            if (stack.size() < 2) {
                throw runtime_error("invalid postfix expression");
            }

            double b = stack.top();
            stack.pop();

            double a = stack.top();
            stack.pop();

            double result = 0;

            if (val == "+") {
                result = a + b;
            }
            else if (val == "-") {
                result = a - b;
            }
            else if (val == "*") {
                result = a * b;
            }
            else if (val == "/") {
                result = a / b;
            }

            stack.push(result);
        }
        else {
            throw runtime_error("invalid token");
        }
    }

    if (stack.size() != 1) {
        throw runtime_error("invalid postfix expression");
    }

    return stack.top();
}
// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
