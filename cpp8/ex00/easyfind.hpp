#pragma once

#include <iostream>
#include <algorithm>

#define RESET "\033[0m"
#define PINK "\033[1;38;2;255;20;147m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define GREEN "\033[1;38;2;;196;0;128m"
#define BLUE "\033[1;38;2;188;238;255m"
#define RED "\033[1;38;2;254;73;73m"
#define GRAS "\033[1m"

using std::cout;
using std::endl;
using std::string;


template<class T>
typename T::const_iterator easyfind(const T &cont, const int &n) {
    typename T::const_iterator it = std::find(cont.cbegin(), cont.cend(), n);
        if (it != cont.cend())
            return it;
    throw std::runtime_error("value not found in container");
}