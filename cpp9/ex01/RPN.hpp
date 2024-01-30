#pragma once

#include <fstream>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

class RPN {
    public :
        
        RPN(const RPN &copy);
        RPN(string input);
        RPN &operator=(const RPN &res);
        ~RPN();
        //void    Rpn();
        void    displayStack();
        void    perform(const string &inp);
    private:
        string input;
        RPN();
        std::stack<int> stack_;


};