#include "Character.hpp"

Character::Character() : name("Defaut") {
    cout  << ORANGE << "Character Constructor called" << RESET << endl;
    for (int i=0;i<4;i++)
        this->inventory[i] = NULL;
}

Character::Character(string name) : name(name) {
    cout  << ORANGE << "Character Constructor called" << RESET << endl;
    for (int i=0;i<4;i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const &copy) : name(copy.name) {
    for (int i = 0; i < 4; i++) {
        if (copy.inventory[i] != NULL)
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character &Character::operator=(Character const &res) {
    if (this != &res) {
        for (int i = 0; i < 4;i++) {
            if (this->inventory[i] != NULL)
                delete inventory[i];
                this->inventory[i] = NULL;
            if (res.inventory[i] != NULL)
                this->inventory[i] = res.inventory[i]->clone();      
        }
    }
    return *this;
}

Character::~Character() {
    // for (int i = 0; i < 4; i++) {
    //     delete this->inventory[i];
    // }
    cout  << VIOLET << "Character Destructor called" << RESET << endl;
}

string const & Character::getName() const {
    return this->name;
}

void Character::use(int idx, ICharacter& target) {
    if (idx > 3 || idx < 0 || this->inventory[idx] == NULL) {
        cout << "can't use this materia" << endl;
        return;
    }     
    this->inventory[idx]->use(target);
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx <= 3) {
        if (this->inventory[idx] != NULL)
            this->inventory[idx] = NULL;
    }
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4;i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            break;
        }
    }
}