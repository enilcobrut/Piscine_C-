#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class RobotomyRequestForm : public Form {
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm(const string target);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &res);
        ~RobotomyRequestForm();
        const string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private :
        const string target;

};