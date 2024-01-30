#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""),Hit_point(10), Energy_point(10),   Attack_damage(0){
    cout << "ClapTrap constructor is called" << endl;
}

ClapTrap::ClapTrap(const string &name) : name(name), Hit_point(10), Energy_point(10), Attack_damage(0) {
    cout << "ClapTrap constructor string is called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
    cout << "ClapTrap constructor copy is called" << endl;
    *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
    if (this != &claptrap) {
        this->Attack_damage = claptrap.Attack_damage;
        this->Energy_point = claptrap.Energy_point;
        this->Hit_point = claptrap.Hit_point;
        this->name = claptrap.name;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target) {
    if (this->Energy_point > 0 && this->Hit_point > 0) {
        cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << endl;
        this->Energy_point -= 1;
    }
    else
        cout << "ClapTrap " << this->name << " has no enought energy point or hit point left" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    cout << "ClapTrap " <<this->name << " has recieved " << amount << " damages" << endl;
    this->Hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
     if (this->Energy_point > 0 && this->Hit_point > 0) {
        cout << "ClapTrap " << this->name << " get Healed by " << amount << " energy point" << endl;
        this->Hit_point += amount;
        this->Energy_point -= 1;
    }
    else
        cout << "ClapTrap " << this->name << " has no enought energy point or hit point left" << endl;

}

ClapTrap::~ClapTrap() {
    cout << "ClapTrap destructor is called" << endl;
}
