#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this == &other)
        return *this;
    _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2)
                throw std::runtime_error("invalid expression");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            if (token == "+") _stack.push(a + b);
            else if (token == "-") _stack.push(a - b);
            else if (token == "*") _stack.push(a * b);
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("division by zero");
                _stack.push(a / b);
            }
        }
        else {
            if (token.size() != 1 || !std::isdigit(token[0]))
                throw std::runtime_error("invalid token: " + token);
            _stack.push(token[0] - '0');
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("invalid expression");

    return _stack.top();
}