#include "Cat.hpp"
#include <iostream>
using std::string;

Cat::Cat() {
    cout << ORANGE << "Cat constructor" << RESET << endl;
    this->type = "Cat";
    this->brain = new Brain();
}
Cat::Cat(const Cat  &copy) : Animal(copy) {
    cout << ORANGE << "Cat copy constructor" << RESET << endl;
    this->brain = new Brain(*copy.getBrain());
}

Cat &Cat::operator=(Cat const &res) {
    if (this != &res) {
        this->brain = new Brain(*res.getBrain());
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

Brain   *Cat::getBrain() const {
    return this->brain;
}

Cat::~Cat() {
    cout << VIOLET << "Cat destructor" << RESET << endl;
   delete this->brain;
}