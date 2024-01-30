#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main () {
    ClapTrap adc("jinx");
    ScavTrap jungle("cassio");
    FragTrap support("lulu");
    adc.attack("tower");
    adc.takeDamage(20);
    adc.beRepaired(100);
    jungle.attack("nachor");
    jungle.takeDamage(5);
    jungle.guardGate();
    jungle.beRepaired(10);
    support.attack("tower");
    support.takeDamage(5);
    support.beRepaired(50);
    support.highFivesGuys();
}
