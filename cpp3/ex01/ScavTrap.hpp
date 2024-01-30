#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
    public :
        ScavTrap();
        ScavTrap(ScavTrap &copy);
        ScavTrap(const string &name);
        ScavTrap &operator=(ScavTrap &res);
        void    guardGate();
        void    attack(const string &name);
        ~ScavTrap();
    private :

};