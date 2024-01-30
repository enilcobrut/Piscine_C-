#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie {
    public:
        Zombie();
        Zombie(string name);
        ~Zombie();
        void    annouce();
        string    get_name();
        void    set_name(string name);
    private:
        string name;
};
