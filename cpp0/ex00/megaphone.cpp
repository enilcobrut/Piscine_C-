#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int ac, char **av)
{
    if (ac == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i=1;i < ac;i++)
    {
        string str(av[i]);
        for (size_t j=0;j < str.length();j++)
            cout << (char)toupper(str[j]);
    }
    cout << endl;
}
