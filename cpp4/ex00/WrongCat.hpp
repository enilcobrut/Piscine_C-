#pragma once
#include "WrongAnimal.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class WrongCat: public WrongAnimal {
    public :
        WrongCat();
        WrongCat(const WrongCat  &copy);
        WrongCat &operator=(WrongCat const &res);
        void makeSound();
        string getType();
        ~WrongCat();
    private :


};