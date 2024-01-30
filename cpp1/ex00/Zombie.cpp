#include "Zombie.hpp"


Zombie::Zombie() {

}

Zombie::~Zombie() {
    cout << this->name << " is destroy" << endl;
}

Zombie::Zombie(string name) : name(name) {

}

void    Zombie::annouce() {
    cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}

string Zombie::get_name() {
    return (this->name);
}

void Zombie::set_name(std::string name) {
    this->name = name;
}