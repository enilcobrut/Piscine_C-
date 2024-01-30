#include "DiamondTrap.hpp"



int main () {
    ClapTrap adc("jinx");
    ScavTrap jungle("cassio");
    FragTrap support("lulu");
    DiamondTrap top("garen");
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
    top.attack("herald");
    top.beRepaired(50);
    top.takeDamage(10);
    top.whoAmI();
}
