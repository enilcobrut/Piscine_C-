#include "Weapon.hpp"

using std::string;

Weapon::Weapon() {

}
Weapon::Weapon(string str) : type(str) {

}

Weapon::~Weapon() {

}

const string & Weapon::getType() {
    return this->type;
}
void    Weapon::setType(string new_type) {
    this->type = new_type;
}

