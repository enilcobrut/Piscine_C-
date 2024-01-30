#pragma once

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define ORANGE "\033[1;38;2;255;187;54m"
#define VIOLET "\033[1;38;2;158;46;156m"
#define BLUE "\033[1;38;2;73;153;254m"
#define RED "\033[1;38;2;255;0;0m"
#define GREEN "\033[1;38;2;69;176;26m"
#define YELLOW "\033[1;38;2;241;223;9m"
#define PINK "\033[1;38;2;240;170;223m"
#define CYAN "\033[1;38;2;43;236;195m"
#define JAUNE "\033[1;38;2;251;255;66"
#define RESET "\033[0m"


class PmergeMe {
    public :
        PmergeMe() {};
        PmergeMe(const PmergeMe &copy);
        PmergeMe(int numbers);
        PmergeMe(PmergeMe *a, PmergeMe *b);
        PmergeMe &operator=(const PmergeMe &arg);
        bool operator>(const PmergeMe& lhs);
        bool operator<(const PmergeMe& lhs);
        int getNumber() const;
        PmergeMe *getA() const;
        PmergeMe *getB() const;
        void swap(PmergeMe *a, PmergeMe *b);
        ~PmergeMe();
        private :
            int numbers;
            PmergeMe *a;
            PmergeMe *b;
    };

