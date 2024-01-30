#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->Hit_point = 100;
    this->Energy_point = 50;
    this->Attack_damage = 20;
    this->name = "";
    cout << "ScavTrap constructor called" << endl;
}


ScavTrap::ScavTrap(const string &name) : ClapTrap() {
    this->name = name;
    this->Hit_point = 100;
    this->Energy_point = 50;
    this->Attack_damage = 20;
    cout << "ScavTrap Constructor string is called" << endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy) {
    cout << "ScavTrap constructor called" << endl;
}
ScavTrap &ScavTrap::operator=(ScavTrap &res) {
    if(this != &res)
        ClapTrap::operator=(res);
    return *this;

}
void ScavTrap::attack(const std::string& target) {
    if (this->Energy_point > 0 && this->Hit_point > 0) {
        cout << "ScavTrap " <<this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << endl;
        this->Energy_point -= 1;
    }
    else
        cout << "ScavTrap  " <<this->name << " has no enought energy point or hit point left" << endl;
}

ScavTrap::~ScavTrap() {
    cout << "ScavTrap destructor called" << endl;
}

void    ScavTrap::guardGate() {
    cout << "Scav Trap is in Gate keeper mode" << endl;
}