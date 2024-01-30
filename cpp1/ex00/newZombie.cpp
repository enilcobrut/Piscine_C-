#include <iostream>
#include "Zombie.hpp"

using std::string;

Zombie* newZombie( std::string name ) {
    Zombie *res = new Zombie(name);
    return (res);
}
