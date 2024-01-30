#include <iostream>
#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;
using std::string;


int main(int ac, char **av) {
    if (ac != 2) {
        cout << "USAGE: ./btc input.txt" << endl;
        exit(1);
    }
    string input1(av[1]);
    try  {
        BitcoinExchange test(input1);
        test.bitcoin();        
    }
    catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}

}