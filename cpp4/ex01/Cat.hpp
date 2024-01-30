#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Brain;

class Cat: public Animal {
    public :
        Cat();
        Cat(const Cat  &copy);
        Cat &operator=(Cat const &res);
        virtual void    makeSound() const;
        virtual string getType() const;
        Brain   *getBrain() const;
        virtual ~Cat();
    private :
        Brain *brain;


};