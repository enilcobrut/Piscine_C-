#include "BitcoinExchange.hpp"
#include <sstream>
#include <string>
using std::getline;
BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}
BitcoinExchange::BitcoinExchange(string input) : input(input), file(input) , data("data.csv") , line(""){
    this->float_value = 0;
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    if (this->input.length() < 4 || (this->input.substr(this->input.length() - 4) != ".txt" && this->input.substr(this->input.length() - 4) != ".csv"))
        throw std::runtime_error("file must be a .txt or .csv");
    string line;
    getline(data, line);
    while (getline(data, line, '\n'))
        this->map_.insert(std::pair<std::string, float>(line.substr(0, line.find_first_of(",")), atof(line.substr(line.find_first_of(",") + 1).c_str())));
}


bool BitcoinExchange::is_valid_date(int year, int month, int day) {
    
    if (year < 2009 || year > 2022)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month == 2) {
        if (day > 29)
            return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
    return true;
}
string  BitcoinExchange::getLine() const {
    return this->line;
}

bool    BitcoinExchange::validate(string date) {
    if (date.length() != 10) {
        cout << "Error: bad input => " << this->line << endl;
        return false;
    }
    string years = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8,2);
    string compare = years + "-" + month + "-" + day;

    if (!is_valid_date(atoi(years.c_str()), atoi(month.c_str()), atoi(day.c_str())) || date != compare)
    {
        cout << "Error: bad input => " << this->line << endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::validvalue(std::string value) {
    float num = static_cast<float>(std::atof(value.c_str()));
    if (num == 0 && value != "0") {
        cout << "Error: not a valid float." << endl;
        return false;
    }
    if (num < 0) {
        cout << "Error: not a positive number." << endl;
        return false;
    }
    if (!(num >= 0 && num <= 1000)) {
        cout << "Error: too large a number." << endl;
        return false;
    }
    this->float_value = num;
    return true;
}

void    BitcoinExchange::bitcoin() {
    getline(this->file, line);
    if (line != "date | value")
        throw std::runtime_error("missing date | value");
    while (getline(this->file, line)) {
        if (line == "")
            continue;
        else {
            size_t pos = line.find('|');
            string date = line.substr(0, pos);
            date.erase(remove(date.begin(), date.end(), ' '), date.end());
            string value = line.substr(pos + 1);
            value.erase(remove(value.begin(), value.end(), ' '), date.end());
            if (pos == string::npos || value.empty() || date.empty())
                cout << "Error: bad input => " << line << endl;
            else {
                    float exchange_rate = 0;
                if (validate(date) && validvalue(value)) {
            
                    std::map<string, float>::iterator it = this->map_.find(date);
                    if (it != this->map_.end()) {
                        exchange_rate = it->second;
                    }
                    else if (!this->map_.empty()) {
                        it = this->map_.lower_bound(date);
                        if (it != this->map_.begin()) {
                            it = std::prev(it);
                            exchange_rate = it->second;
                        }
                                            }
                cout << date << " => " << this->float_value << " = " << exchange_rate * this->float_value << endl;
                }

            }
        }
    }
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &res) {
    (void)res;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {

}