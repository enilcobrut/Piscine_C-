#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main() {
    Zombie zombie("Sasso");
    zombie.annouce();
    randomChump("Mayoub");
    Zombie *fafa = newZombie("Fafa");
    fafa->annouce();
    delete fafa;
}
