#include "ClapTrap.hpp"

int main () {
    ClapTrap adc("jinx");
    adc.attack("tower");
    adc.takeDamage(5);
    adc.beRepaired(10);
    for (int i = 0;i<9;i++)
        adc.attack("nachor");
}