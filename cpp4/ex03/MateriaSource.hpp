#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#define WHITE "\033[38;2;255;255;255m"
#define GRAS "\033[1m"
#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define VIOLET "\033[1;38;2;158;46;156m"
#define ICE "\033[1;38;2;188;238;255m"
#define VIOLET "\033[1;38;2;158;46;156m"

using std::cout;
using std::endl;
using std::string;
class ICharacter;
class AMateria;



class MateriaSource : public IMateriaSource {
    public :
        MateriaSource();
        MateriaSource(MateriaSource const &copy);
        MateriaSource &operator=(MateriaSource const &res);
        ~MateriaSource();
        void learnMateria(AMateria*mat);
        AMateria* createMateria(std::string const & type);
    private :
        AMateria    *inventorySource[4];

};