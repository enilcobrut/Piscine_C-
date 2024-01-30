#include "Animal.hpp"
#include <iostream>
using std::string;

Animal::Animal() {
    cout << ORANGE << "Animal constructor" << RESET << endl;
    this->type = "";
}
Animal::Animal(const Animal  &copy) {
    cout << ORANGE << "Animal copy constructor" << RESET << endl;
    *this = copy;
}
void Animal::makeSound() const {
    cout << JAUNE << "Animal Sound" << RESET << endl;
}

Animal &Animal::operator=(Animal const &res) {
    if (this != &res) {
        this->type = res.type;
    }
    return *this;
}
string  Animal::getType() const{
    return this->type;
}

Animal::~Animal() {
    cout << VIOLET << "Animal destructor" << RESET << endl;
}