#include "ScavTrap.hpp"

int main () {
    ClapTrap adc("jinx");
    ScavTrap jungle("cassio");
    adc.attack("tower");
    adc.takeDamage(20);
    adc.beRepaired(100);
    jungle.attack("nachor");
    jungle.takeDamage(5);
    jungle.guardGate();
    jungle.beRepaired(10);
}
