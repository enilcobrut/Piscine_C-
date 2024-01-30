#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
Intern::Intern() {

}

Intern::Intern(Intern const &copy) {
    *this = copy;
}

Intern &Intern::operator=(Intern const &res) {
    (void)res;
    return *this;
}

Intern::~Intern() {

}

Form *Intern::makeForm(string name, string target) {
    string form[3] = { "presidential pardon",
                        "robotomy request",
                        "shrubbery creation"
                    };
                    int filter = -1;
                    for (int i = 0;i < 3;i++) {
                        if (form[i] == name)
                            filter = i;
                    }
                    switch (filter) {
                        case 0:
                            return new PresidentialPardonForm(target);
                        case 1:
                            return new RobotomyRequestForm(target);
                        case 2:
                            return new ShrubberyCreationForm(target);
                        default:
                            throw std::invalid_argument("form not found");
                    }

}