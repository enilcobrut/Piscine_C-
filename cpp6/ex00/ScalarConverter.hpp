#pragma once


#include <iostream>

using std::cout;
using std::endl;
using std::string;



class ScalarConverter {
    public :
        ScalarConverter(ScalarConverter const &copy);
        ScalarConverter &operator=(ScalarConverter const &res);
        ~ScalarConverter();
        static void convert(string input);  
    private :
        ScalarConverter();
};
