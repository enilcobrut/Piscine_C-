#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) ,target("defaut") {

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy), target(copy.target) {

}
RobotomyRequestForm::RobotomyRequestForm(const string target) : Form("RobotomyRequestForm", 145, 137), target(target){

}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &res) {
    if (this != &res) 
      cout << "const can not be assignable" << endl;
    return *this;
}

const string RobotomyRequestForm::getTarget() const {
    return this->target;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getSign())
     throw Form::NotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    cout << "bruit de perceuse" << endl;
    srand(time(NULL));
    int Rand = rand() % 2;
    if (Rand)
        cout << this->getTarget() << "  a été robotomisée" << endl;
    else
        cout << "operation a echouer" << endl;

}

RobotomyRequestForm::~RobotomyRequestForm() {

}