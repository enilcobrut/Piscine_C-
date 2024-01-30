#pragma once
#include "Animal.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Cat: public Animal {
    public :
        Cat();
        Cat(const Cat  &copy);
        Cat &operator=(Cat const &res);
        virtual void    makeSound() const;
        virtual string getType() const;
        ~Cat();
    private :


};