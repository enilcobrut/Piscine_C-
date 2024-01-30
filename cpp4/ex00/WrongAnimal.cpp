#include "WrongAnimal.hpp"
#include <iostream>
using std::string;

WrongAnimal::WrongAnimal() {
    cout << ORANGE << "WrongAnimal constructor" << RESET << endl;
    this->type = "";
}
WrongAnimal::WrongAnimal(const WrongAnimal  &copy) {
    cout << ORANGE  << "WrongAnimal copy constructor" << RESET << endl;
    *this = copy;
}
void WrongAnimal::makeSound() const {
    cout << JAUNE <<"WrongAnimal Sound" << RESET << endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &res) {
    if (this != &res) {
        this->type = res.type;
    }
    return *this;
}
string  WrongAnimal::getType() const{
    return this->type;
}

WrongAnimal::~WrongAnimal() {
    cout << VIOLET << "WrongAnimal destructor" << RESET << endl;
}