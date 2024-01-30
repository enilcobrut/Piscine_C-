#pragma once

#include <iostream>

using std::string;

class Weapon {
    public:
        Weapon();
        Weapon(string str);
        ~Weapon();
        const string &getType();
        void    setType(string new_type);

    private:
        string type;
};