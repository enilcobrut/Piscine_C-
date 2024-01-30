#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class ClapTrap {
    public :
        ClapTrap();
        ClapTrap(const string &name);
        ClapTrap(const ClapTrap &claptrap);
        ClapTrap &operator=(const ClapTrap &claptrap);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        string  getName() const;
        virtual ~ClapTrap();
    protected :
        string name;
        int Hit_point;
        int Energy_point;
        int Attack_damage;
    
};
