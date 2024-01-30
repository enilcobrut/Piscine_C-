#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class PresidentialPardonForm : public Form {
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm(const string target);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &res);
        ~PresidentialPardonForm();
        const string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private :
        const string target;

};