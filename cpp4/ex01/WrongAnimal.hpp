#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

#define WHITE "\033[38;2;255;255;255m"
#define GRAS "\033[1m"
#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define VIOLET "\033[1;38;2;158;46;156m"
#define JAUNE "\033[1;38;2;241;255;149m"
#define BLEU "\033[1;38;2;18;39;176m"


class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal  &copy);
        WrongAnimal &operator=(WrongAnimal const &res);
        string    getType() const;
        void    makeSound() const;
        virtual ~WrongAnimal();
    protected:
        string type;
};