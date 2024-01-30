#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
    string String = "HI THIS IS BRAIN";
    string *stringPTR = &String;
    string &stringREF = String;

    cout << &String << endl;
    cout << stringPTR << endl;
    cout << &stringREF << endl;

    cout << String << endl;
    cout << *stringPTR << endl;
    cout << stringREF << endl;
}
