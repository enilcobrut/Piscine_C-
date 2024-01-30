#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        cout << "only need one args" << endl;
        return (1);
    }
    Harl harl;
    string str(av[1]);
    harl.complain(str);
}
