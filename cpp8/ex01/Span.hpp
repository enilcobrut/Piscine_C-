#pragma once

#include <iostream>

#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define GREEN "\033[1;38;2;;196;0;128m"
#define BLUE "\033[1;38;2;50;200;255m"
#define RED "\033[1;38;2;254;73;73m"
#define GRAS "\033[1m"

using std::cout;
using std::endl;
using std::string;


class Span {
    public :
        
        Span(const Span &copy);
        Span(unsigned int N);
        Span &operator=(const Span &res);
        void addNumber(int n);
        template<typename InputIterator>
        void addRange(InputIterator first, InputIterator last) {
            while (first != last && this->count < this->N) {
                addNumber(*first);
                ++first;
            }
        }
        unsigned int shortestSpan();
        unsigned int longestSpan();
        virtual ~Span();
    private :
        Span();
        unsigned int N;
        unsigned int count;
        int *tab;
};