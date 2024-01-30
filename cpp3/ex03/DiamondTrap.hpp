#pragma once

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

using std::string;


class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        DiamondTrap(DiamondTrap &copy);
        DiamondTrap(const string &name);
        DiamondTrap &operator=(DiamondTrap &res);
        ~DiamondTrap();
        void attack(const string &name);
        string  getName() const;
        void whoAmI();
    private:
        string name;
};

