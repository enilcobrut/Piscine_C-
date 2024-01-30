#pragma once

#include <iostream>
#include "Weapon.hpp"

using std::string;

class HumanB {
    public :
        HumanB();
        HumanB(string str);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon &weapon);
        
    private :
        string name;
        Weapon *weapon;
};