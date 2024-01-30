#include "Dog.hpp"
#include <iostream>
using std::string;

Dog::Dog() {
    cout << ORANGE << "Dog constructor" << RESET << endl;
    this->type = "Dog";
}
Dog::Dog(const Dog  &copy) {
    cout << ORANGE << "Dog copy constructor" << RESET << endl;
    *this = copy;
}

Dog &Dog::operator=(Dog const &res) {
    if (this != &res) {
        this->type = res.type;
    }
    return *this;
}

string  Dog::getType() const{
    return this->type;
}

void    Dog::makeSound() const{
    cout << PINK << "WOAF" << RESET << endl;
}

Dog::~Dog() {
    cout << VIOLET << "Dog destructor" << RESET << endl;
}