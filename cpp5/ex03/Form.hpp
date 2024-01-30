#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
using std::cout;
using std::endl;
using std::string;
using std::ostream;
class Bureaucrat;
class Form {
    public :
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        Form();
        Form(Form const &copy);
        Form(const string name, const int gradeSign, const int gradeExec);
        Form &operator=(Form const &res);
        virtual ~Form();
        const string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
    private :
        const string name;
        bool sign;
        const int gradeSign;
        const int gradeExec;
};

std::ostream	&operator<<(std::ostream &o, Form const &i);