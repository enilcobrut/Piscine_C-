#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
    cout  << ORANGE << "Ice Constructor called" << RESET << endl;
}
Ice::Ice(Ice const &copy) : AMateria(copy) {

}
Ice &Ice::operator=(Ice const &res) {
    if (this != &res) {
        this->AMateria::operator=(res);
    }
    return *this;
}

Ice::~Ice() {
    cout  << VIOLET << "Ice Destructor called" << RESET << endl;
}
AMateria *Ice::clone() const {
    return new Ice();
}
