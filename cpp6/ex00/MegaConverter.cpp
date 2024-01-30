#include "MegaConverter.hpp"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <ctype.h>

MegaConverter::MegaConverter() : i_res(0) ,d_res(0), c_res(0) {

}
MegaConverter::MegaConverter(MegaConverter const &copy) {
    *this=copy;
}


MegaConverter &MegaConverter::operator=(MegaConverter const &res) {
    if (this != &res) {
        this->input = res.input;
        this->i_res = res.i_res;
        this->d_res = res.d_res;
        this->c_res = res.c_res;
    }
    return *this;
}
MegaConverter::MegaConverter(string type) : input(type)  {
    this->i_res = 0;
    this->d_res = 0;
    this->c_res = 0;
}


int    MegaConverter::getInt() {
    return this->i_res;
}
double MegaConverter::getDouble() {
    return this->d_res;
}
char   MegaConverter::getChar() {
    return this->c_res;
}


void    MegaConverter::setInt(int i_res) {
    this->i_res = i_res;
}
void    MegaConverter::setDouble(double d_res) {
    this->d_res = d_res;
}
void    MegaConverter::setChar(char c_res) {
    this->c_res = c_res;
}

type MegaConverter::WhichType() {
    bool isInt = true;
    bool isDouble = true;
    int nb_dot = 0;
    int nb_f = 0;
    if ((this->input[0] == '-' && this->input.length() > 1) || (this->input[0] == '+' && this->input.length() > 1)) {
        string new_input(this->input.substr(1, input.length()-1));
        this->input = new_input;
    }
    for (size_t i=0; this->input[i]; i++) {
        if (this->input[i] == '.') {
                nb_dot++;
        }
        if (this->input[i] == 'f') {
                nb_f++;
        }
        if (!isdigit(this->input[i])) {
            if (this->input[i] != '.' && this->input[i] != 'f')
                isDouble = false;
            isInt = false;
        }
    }
    if (isInt) {
        long int num = atol(this->input.c_str());
        if (num > INT_MAX || num < INT_MIN) {
            throw std::invalid_argument("impossible");
        }
        return INT; 
    }
    if ((isDouble && nb_dot == 1 && nb_f == 0) || this->input == "nan" || this->input == "nanf" || this->input == "inf" || this->input == "inff" || (this->input[this->input.length() - 1] == 'f' && isDouble && nb_dot == 1 && nb_f == 1)) {
        return DOUBLE;
    }
    if (this->input.length() == 1)
        return CHAR;
    return NONE;
}

int MegaConverter::TypeToInt(type type_) {
    switch (type_) {
        case INT:
            return atoi(this->input.c_str());
        case DOUBLE:
            
            if (this->input == "inf" || this->input == "inff" || this->input == "nan" || this->input == "nanf") {
                 throw std::invalid_argument("impossible");
            
            }
            return static_cast<int>(this->d_res);
        case CHAR:
            if (this->input.length() == 1) {
                return static_cast<int>(this->c_res);
            } else {
                throw std::invalid_argument("Invalid input for char type");
            }
        default:
            throw std::invalid_argument("Invalid type");
    }
}
double MegaConverter::TypeToDouble(type type_) {
    switch (type_) {
        case INT:
            return static_cast<double>(std::atof(this->input.c_str()));
        case DOUBLE:
            return static_cast<double>(std::stod(this->input));
        case CHAR:
            return static_cast<double>(static_cast<int>(this->c_res));
        default:
            throw std::invalid_argument("Invalid type");
    }
}

char  MegaConverter::TypeToChar(type type_) {        
       switch (type_) {
        case INT:
            if (this->i_res < 0 || this->i_res > 127)
            {
                throw std::invalid_argument("impossible");
            }
            else if ((this->i_res >= 0 && this->i_res <= 32) || this->i_res == 127)
                throw std::invalid_argument("Non displayable");
            else
                return static_cast<char>(this->i_res);
        case DOUBLE:
            if (this->d_res < 0 || this->d_res > 127 || this->input == "inf" || this->input == "inff"|| this->input == "nan" || this->input == "nanf")
            {
                throw std::invalid_argument("impossible");
            }
            else if ((this->d_res >= 0 && this->d_res <= 32) || this->d_res == 127)
                throw std::invalid_argument("Non displayable");
            return static_cast<char>(static_cast<int>(this->d_res));
        case CHAR:
            return static_cast<char>(this->c_res);
        default:
            throw std::invalid_argument("Invalid type");
    }
}
