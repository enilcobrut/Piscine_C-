#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class ShrubberyCreationForm : public Form {
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm(const string target);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &res);
        ~ShrubberyCreationForm();
        const string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private :
        const string target;

};