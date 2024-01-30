#pragma once
#include <iostream>
#include "Form.hpp"
using std::cout;
using std::endl;
using std::string;
using std::ostream;
class Form;
class Bureaucrat {
    public :
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        Bureaucrat();
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat(const string name, int grade);
        Bureaucrat &operator=(Bureaucrat const &res);
        ~Bureaucrat();
        const string getName() const;
        int getGrade() const;
        void IncGrade();
        void DecGrade(); 
        void signForm(Form  &form) const;
        void   executeForm(Form const & form);
    private :
        
        const string name;
        int grade;
};



ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

