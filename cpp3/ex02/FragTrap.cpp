#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->Hit_point = 100;
    this->Energy_point = 100;
    this->Attack_damage = 30;
    this->name = "";
    cout << "FragTrap constructor called" << endl;
}

FragTrap::FragTrap(const string &name) : ClapTrap() {
    this->Hit_point = 100;
    this->Energy_point = 100;
    this->Attack_damage = 30;
    this->name = name;
    cout << "FragTrap constructor called" << endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy) {
    cout << "FragTrap constructor called" << endl;
}
FragTrap &FragTrap::operator=(FragTrap &res) {
    if(this != &res)
        ClapTrap::operator=(res);
    return *this;

}

void FragTrap::highFivesGuys(void) {
    cout << "High Five" << endl;
}

FragTrap::~FragTrap() {
    cout << "FragTrap destructor called" << endl;
}
