#include <iostream>
#include "MegaConverter.hpp"
#include "ScalarConverter.hpp"
using std::cout;
using std::endl;

int main(int ac, char **av) {
    if (ac != 2) {
        cout << "only one arg" << endl;
        exit(1);
    }
    string input(av[1]);
    ScalarConverter::convert(input);

}