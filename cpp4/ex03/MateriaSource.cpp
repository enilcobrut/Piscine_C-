#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    cout  << ORANGE << "MateriaSource Constructor called" << RESET << endl;
    for (int i=0;i<4;i++)
        this->inventorySource[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
    *this = copy;
}
MateriaSource &MateriaSource::operator=(MateriaSource const &res) {
    if (this != &res) {
        for (int i=0;i<4;i++)
            this->inventorySource[i] = res.inventorySource[i];
    }
    return *this;
}
MateriaSource::~MateriaSource() {
    cout  << VIOLET << "MateriaSource Destructor called" << RESET << endl;
}
void MateriaSource::learnMateria(AMateria *mat) {
    for (int i = 0; i < 4; i++ ) {
       // cout << "learn i : " << i << endl;
        if (this->inventorySource[i] == NULL) {
            this->inventorySource[i] = mat;
           // cout << "learn : " << this->inventorySource[i]->getType() << endl;
            return;
        }
    }

}
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->inventorySource[i] && this->inventorySource[i]->getType() == type) {
            return this->inventorySource[i]->clone();
        }
    }
    return NULL;
}