#include "HumanA.hpp"

using std::cout;
using std::endl;


HumanA::HumanA(string str, Weapon &weapon) : name(str), weapon(weapon) {

}

HumanA::~HumanA() {

}

void HumanA::attack() {
    cout << this->name << " attacks with their " << weapon.getType() << endl;
}