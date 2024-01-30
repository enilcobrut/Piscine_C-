#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum type {
    INT,
    DOUBLE,
    CHAR,
    NONE
};

class MegaConverter {
    public :
        MegaConverter();
        MegaConverter(MegaConverter const &copy);
        MegaConverter &operator=(MegaConverter const &res);
        MegaConverter(string type);
        type WhichType();
        int  TypeToInt(type type_);
        double TypeToDouble(type type_);
        char  TypeToChar(type type_);
        void    setInt(int i_res);
        void    setDouble(double d_res);
        void    setChar(char c_res);
        int     getInt();
        double  getDouble();
        char    getChar();

    private :
        int i_res;
        double d_res;
        char c_res;
        string  input;

};