#include "Dog.hpp"
#include <iostream>
using std::string;

Dog::Dog() {
    cout << ORANGE << "Dog constructor" << RESET << endl;
    this->type = "Dog";
    this->brain = new Brain();
}
Dog::Dog(const Dog  &copy) : Animal(copy) {
    cout << ORANGE << "Dog copy constructor" << RESET << endl;
    this->brain = new Brain(*copy.getBrain());
}

Dog &Dog::operator=(Dog const &res) {
    if (this != &res) {
        this->type = res.type;
        this->brain = new Brain(*res.getBrain());
    }
    return *this;
}

Brain   *Dog::getBrain() const {
    return this->brain;
}


string  Dog::getType() const{
    return this->type;
}

void    Dog::makeSound() const{
    cout << PINK << "WOAF" << RESET << endl;
}

Dog::~Dog() {
    cout << VIOLET <<"Dog destructor" << RESET << endl;
   delete this->brain;
}