#include "Form.hpp"


Form::Form(Form const &copy) : name(copy.name), sign(copy.sign), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec){
        if (gradeSign < 1 || gradeExec < 1)
            throw Form::GradeTooHighException();
        if (gradeSign > 150 || gradeExec > 150)
            throw Form::GradeTooLowException();

}

Form::Form() : name("default"), sign(false), gradeSign(150), gradeExec(150) {

}

Form::Form(const string name, const int gradeSign, const int gradeExec) : name(name), sign(false), gradeSign(gradeSign), gradeExec(gradeExec) {
         if (gradeSign < 1 || gradeExec < 1)
            throw Form::GradeTooHighException();
        if (gradeSign > 150 || gradeExec > 150)
            throw Form::GradeTooLowException();
}

Form &Form::operator=(Form const &res) {
    if (this != &res) {
        this->sign = res.sign;
    }
    return *this;
}
Form::~Form() {

}
void    Form::beSigned(Bureaucrat const &bureaucrat)  {
    if (bureaucrat.getGrade() <= this->gradeSign)
        this->sign = true;
    else
        throw Form::GradeTooLowException();

}

const char *Form::GradeTooLowException::what() const throw() {
                return "Bureaucrat is too low!";
}

const char* Form::NotSignedException::what() const throw() {
                    return "Error: Form not signed!";
}

const char *Form::GradeTooHighException::what() const throw() {
                return "Bureaucrat is too high!";
}



const string Form::getName() const {
    return this->name;
}

int Form::getGradeSign() const {
    return this->gradeSign;
}
int Form::getGradeExec() const {
    return this->gradeExec;
}

bool Form::getSign() const {
    return this->sign;
}

std::ostream	&operator<<( std::ostream &o, Form const &i ) {

	o << "The " << i.getName() << " need a Bureaucrat with  " << i.getGradeSign() << "grade to be signed and " << i.getGradeExec() << "to be execute." << endl;

	return (o);
}
