#pragma once
#include "Animal.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Dog: public Animal {
    public :
        Dog();
        Dog(const Dog  &copy);
        Dog &operator=(Dog const &res);
        virtual void    makeSound() const;
        virtual string getType() const;
        ~Dog();
    private :


};