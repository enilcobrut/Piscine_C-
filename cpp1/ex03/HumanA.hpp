#pragma once

#include <iostream>
#include "Weapon.hpp"

using std::string;

class HumanA {
    public :
        HumanA(string str, Weapon &weapon);
        ~HumanA();
        void    attack();
    private :
        string name;
        Weapon &weapon;
};
