#include "WrongCat.hpp"
#include <iostream>
using std::string;

WrongCat::WrongCat() {
    cout << ORANGE << "WrongCat constructor" << RESET  << endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat  &copy) {
    cout << ORANGE << "WrongCat copy constructor" << RESET<< endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &res) {
    if (this != &res) {
        this->type = res.type;
    }
    return *this;
}

string  WrongCat::getType() {
    return this->type;
}

void    WrongCat::makeSound() {
    cout << BLEU << "WRONG MIAOU"<< RESET << endl;
}

WrongCat::~WrongCat() {
    cout << VIOLET << "WrongCat destructor" << RESET << endl;
}