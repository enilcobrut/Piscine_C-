#include <iostream>
#include "RPN.hpp"

using std::cout;
using std::endl;
using std::string;


int main(int ac, char **av) {
    if (ac != 2) {
        cout << "Usage : ./RPN \"1 2 3 + + +\"" << endl;
        exit(1);
    }
    string input(av[1]);
     try  {
        RPN rpn(input);
        rpn.displayStack();        
    }
    catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}

}