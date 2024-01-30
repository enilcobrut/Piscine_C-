#include "RPN.hpp"  

RPN::RPN() {

}


RPN::RPN(string input) : input(input) {
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        if (isdigit(c)) {
            int digit = c - '0';
            stack_.push(digit);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack_.size() < 2) {
                throw std::runtime_error("Error : not enought digit");
            }
            int op2 = stack_.top();
            stack_.pop();
            int op1 = stack_.top();
            stack_.pop();
            int result;
            if (c == '+') {
                result = op1 + op2;
            }
            else if (c == '-') {
                result = op1 - op2;
            }
            else if (c == '*') {
                result = op1 * op2;
            }
            else if (c == '/') {
                if (op2 == 0) {
                    throw std::runtime_error("Error : division by zero");
                }
                result = op1 / op2;
            }
            stack_.push(result);
        }
        else {
            throw std::runtime_error("Error : invalid input");
        }
    }
    if (stack_.size() != 1) {
        throw std::runtime_error("Error : not enought operands");
    }
}

void RPN::displayStack() {
     std::stack<int> tempStack = this->stack_;
     while (!tempStack.empty()) {
         cout << tempStack.top() << " ";
         tempStack.pop();
     }
     cout << endl;
}

RPN::RPN(const RPN &copy) {
    *this = copy;
}

RPN &RPN::operator=(const RPN &res) {
    if (this != &res)
        this->input = res.input;
    return *this;
}

RPN::~RPN() {

}