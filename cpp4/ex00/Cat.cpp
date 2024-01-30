#include "Cat.hpp"
#include <iostream>
using std::string;

Cat::Cat() {
    cout << ORANGE << "Cat constructor" << RESET << endl;
    this->type = "Cat";
}
Cat::Cat(const Cat  &copy) {
    cout << ORANGE << "Cat copy constructor" << RESET << endl;
    *this = copy;
}

Cat &Cat::operator=(Cat const &res) {
    if (this != &res) {
        this->type = res.type;
    }
    return *this;
}

string  Cat::getType() const{
    return this->type;
}

void    Cat::makeSound() const{
    cout << BLEU << "MIAOU" << RESET << endl;
}

Cat::~Cat() {
    cout << VIOLET << "Cat destructor" << RESET << endl;
}