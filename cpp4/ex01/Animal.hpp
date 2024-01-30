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


class Animal {
    public:
        Animal();
        Animal(const Animal  &copy);
        Animal &operator=(Animal const &res);
        string    getType() const;
        virtual void    makeSound() const;
        virtual ~Animal();
    protected:
        string type;
};