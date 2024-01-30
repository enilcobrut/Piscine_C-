#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(FragTrap &copy);
        FragTrap(const string &name);
        FragTrap &operator=(FragTrap &res);
        virtual ~FragTrap();
        void highFivesGuys(void);
};