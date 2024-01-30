#pragma once
#include <iostream>
#define WHITE "\033[38;2;255;255;255m"
#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define VIOLET "\033[1;38;2;158;46;156m"
#define ICE "\033[1;38;2;188;238;255m"
#define CURE "\033[1;38;2;;196;0;128m"
using std::cout;
using std::endl;
using std::string;
class ICharacter;

class AMateria
{
    protected:
        string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const &copy);
        AMateria &operator=(AMateria const &res);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};