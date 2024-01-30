#pragma once
#include <iostream>
#include "Form.hpp"
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Intern {
    public:
        Intern();
        Intern(Intern const &copy);
        Intern &operator=(Intern const &res);
        ~Intern();
        Form *makeForm(string name, string target); 
    private:
};