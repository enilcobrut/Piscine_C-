
#pragma once
#include <iostream>
#include "AMateria.hpp"
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

class AMateria;


class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};