#pragma once

#include <fstream>
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

class BitcoinExchange {
    public:
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange(const string input);
        BitcoinExchange &operator=(const BitcoinExchange &res);
        ~BitcoinExchange();
        void    bitcoin();
        bool    validate(string date);
        bool    validvalue(string value);
        string  getLine() const;
        bool is_valid_date(int year, int month, int day);
        

    private :
        BitcoinExchange();
        string input;
        ifstream file;
        ifstream data;
        string line;
        float   float_value;
        std::map<std::string, float> map_;
};