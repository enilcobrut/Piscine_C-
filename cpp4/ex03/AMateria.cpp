#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default") {
    cout  << ORANGE << "AMateria Constructor called" << RESET << endl;
}

AMateria::AMateria(std::string const & type) : type(type)  {

}

AMateria::AMateria(AMateria const &copy) : type(copy.type) {

}
AMateria &AMateria::operator=(AMateria const &res) {
    if (this != &res) {
        this->type = res.type;
    }
    return (*this);
}
AMateria::~AMateria() {
    cout  << VIOLET << "AMateria Destructor called" << RESET << endl;
}
string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    if (this->type == "cure")
        cout << CURE << "* heals " << target.getName() << "'s wounds *" << RESET << endl;
    else if (this->type == "ice")
        cout  << ICE <<  "* shoots an ice bolt at " << target.getName() << RESET << endl;
    else
        cout  << PINK <<  this->type << " is used on " << target.getName() << RESET << endl;
}
