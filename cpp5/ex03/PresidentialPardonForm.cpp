#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) ,target("defaut") {

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy) {
    *this = copy;
}
PresidentialPardonForm::PresidentialPardonForm(const string target) : Form("PresidentialPardonForm", 25, 5), target(target){

}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &res) {
    if (this != &res) 
      cout << "const can not be assignable" << endl;
    return *this;
}

const string PresidentialPardonForm::getTarget() const {
    return this->target;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getSign())
     throw Form::NotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    cout << this->target << " a été pardonnée par Zaphod Beeblebrox" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}