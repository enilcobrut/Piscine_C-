#include <iostream>
#include <fstream>
#define GRAS "\033[1m"
#define PINK "\033[38;2;255;20;147m"
#define RESET "\033[0m"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

void ft_replace(char *name_file, char *s_1, char *s_2) {
    if (!s_1[0]) {
        cout << "error string is empty" << endl;
        return;
    }
    ifstream file(name_file);
    if (!file.good()  || file.bad()) {
        cout << GRAS << PINK << "encounter error while openning the file" << endl;
        exit (1);
    }
    string new_name = string(name_file) + ".replace";
    ofstream new_file(new_name);
    string line;
    string s1(s_1);
    string s2(s_2);
    char c;
    while (file.get(c))
        line += c;
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != string::npos) {
        if (line == "")
            return ;
        string before = line.substr(0, pos);
        string after = line.substr(pos + s1.length());
        line = before + s2 + after;
        pos += s2.length();
    }
    new_file << line;
    file.close();
    new_file.close();
}

int main(int ac, char **av) {
    if (ac != 4) {
        cout << "input must be : <file name> <string one> <string two>" << endl;
        return 1;
    }
    ft_replace(av[1], av[2], av[3]);
}
