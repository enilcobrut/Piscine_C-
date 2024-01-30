#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Defaut"), grade(150) {

}
Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade) {
    *this = copy;
}

Bureaucrat::Bureaucrat(const string name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    else
        this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &res) {
    if (this != &res) {
        this->grade = res.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {

}
const string Bureaucrat::getName() const {
    return this->name;
}
int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::IncGrade() {
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    else
        grade--;

}
void Bureaucrat::DecGrade() {
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    else
        grade++;

}

void    Bureaucrat::signForm(Form  &form) const {
    if (form.getSign()) {
        cout << this->name << " couldn't sign " << form.getName() << " because the form is alrdy signed." << endl;
        return;
    }
    else if (this->grade <= form.getGradeSign() && form.getSign() == false) {
        cout << this->name << " signed " << form.getName() << endl;
        form.beSigned(*this);
    }
    else {
        cout << this->name << " couldn't sign " << form.getName() << " because the grade is not reach." << endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
                return "Bureaucrat is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
                return "Bureaucrat is too low!";
}

void   Bureaucrat::executeForm(Form const & form) {
    try {
        form.execute(*this);
        cout << this->name << " executed " << form.getName() << endl;
    }
    catch (std::exception &e) {
        std::cerr << this->name << " couldn't execute " << form.getName() << " because: " << e.what() << endl;
    }
}

ostream &operator<<(ostream &os, Bureaucrat const &obj) {
    os  << obj.getName() <<  ", bureaucrat grade " << obj.getGrade();
    return os;
}