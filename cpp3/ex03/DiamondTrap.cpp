#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"


DiamondTrap::DiamondTrap() : FragTrap(),  ScavTrap() {
    this->name = "";
    ClapTrap::name = this->name + "_clap_name";
    this->Hit_point = FragTrap::Hit_point;
    this->Energy_point = ScavTrap::Energy_point;
    this->Attack_damage = FragTrap::Attack_damage;
    cout << "DiamondTrap constructor called" << endl;
}

DiamondTrap::DiamondTrap(const string &name) : FragTrap(name),ScavTrap(name)  {
    this->name = name;
    ClapTrap::name = this->name + "_clap_name";
    this->Hit_point = FragTrap::Hit_point;
    this->Energy_point = ScavTrap::Energy_point;
    this->Attack_damage = FragTrap::Attack_damage;
    cout << "DiamondTrap string constructor called" << endl;
}


void    DiamondTrap::attack(const string &name) {
    ScavTrap::attack(name);
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) {
    cout << "DiamondTrap copy constructor called" << endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &res) {
    if (this != &res)
    {
        this->name = res.name;
        this->Hit_point = res.Hit_point;
        this->Energy_point = res.Energy_point;
    }
    return *this;
}
string DiamondTrap::getName() const {
    return name;
}

void DiamondTrap::whoAmI() {
    cout << "DiamondTrap name: " << this->name << endl;
    cout << "ClapTrap name: " << this->ClapTrap::getName() << endl;
}

DiamondTrap::~DiamondTrap() {
    cout << "DiamondTrap destructor called" << endl;
}