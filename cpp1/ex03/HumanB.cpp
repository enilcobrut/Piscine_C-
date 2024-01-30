#include "HumanB.hpp"

using std::cout;
using std::endl;

HumanB::HumanB() {

}

HumanB::HumanB(string str) : name(str) {

}

HumanB::~HumanB() {

}

void    HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    if (weapon)
        cout << this->name << " attacks with their " << weapon->getType() << endl;
}
