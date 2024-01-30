#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#define WHITE "\033[38;2;255;255;255m"
#define GRAS "\033[1m"
#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define VIOLET "\033[1;38;2;158;46;156m"
using std::cout;
using std::endl;
using std::string;

class AMateria;
class ICharacter;


class Ice : public AMateria {
    public :
        Ice();
        Ice(Ice const &copy);
        Ice &operator=(Ice const &res);
        ~Ice();
        AMateria *clone() const;
    private :

};