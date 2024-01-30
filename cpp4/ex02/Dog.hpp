#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
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
        string getType() const;
        Brain   *getBrain() const;
        virtual ~Dog();
    private :
        Brain *brain;


};