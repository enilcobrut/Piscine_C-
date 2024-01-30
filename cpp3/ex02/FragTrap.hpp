#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        FragTrap();
        FragTrap(FragTrap &copy);
        FragTrap(const string &name);
        FragTrap &operator=(FragTrap &res);
        ~FragTrap();
        void highFivesGuys(void);
};