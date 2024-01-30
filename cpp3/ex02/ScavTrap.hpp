#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
    public :
        ScavTrap();
        ScavTrap(ScavTrap &copy);
        ScavTrap &operator=(ScavTrap &res);
        ScavTrap(const string &name);
        void    guardGate();
        void    attack(const string &name);
        ~ScavTrap();
    private :

};
