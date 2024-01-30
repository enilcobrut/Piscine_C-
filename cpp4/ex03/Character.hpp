#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#define WHITE "\033[38;2;255;255;255m"
#define GRAS "\033[1m"
#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define CURE "\033[1;38;2;;196;0;128m"
#define ICE "\033[1;38;2;188;238;255m"

#define VIOLET "\033[1;38;2;158;46;156m"

using std::cout;
using std::endl;
using std::string;
class ICharacter;
class AMateria;

class Character : public ICharacter {
    public:
        Character();
        Character(string name);
        Character(Character const &copy);
        Character &operator=(Character const &res);
        ~Character();
        string const & getName() const;
        void use(int idx, ICharacter& target);
        void equip(AMateria* m);
        void unequip(int idx);
    private:
        string name;
        AMateria    *inventory[4];

};