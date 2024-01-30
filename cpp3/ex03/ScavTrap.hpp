#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {
    public :
        ScavTrap();
        ScavTrap(ScavTrap &copy);
        ScavTrap(const string &name);
        ScavTrap &operator=(ScavTrap &res);
        void    attack(const string &name);
        void    guardGate();
        virtual ~ScavTrap();
    private :

};