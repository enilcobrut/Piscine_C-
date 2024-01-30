#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

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
    private :
        
        const string name;
        int grade;
};

ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

