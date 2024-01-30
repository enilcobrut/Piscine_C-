#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {
    cout  << ORANGE << "Cure Constructor called" << RESET << endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy) {

}

Cure &Cure::operator=(Cure const &res) {
    if (this != &res) {
        this->AMateria::operator=(res);
    }
    return *this;
}

Cure::~Cure() {
    cout  << VIOLET << "Cure Destructor called" << RESET << endl;
}

AMateria *Cure::clone() const {
    return new Cure();
}
