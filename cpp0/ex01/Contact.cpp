#include "Contact.hpp"


Contact::Contact() {

}

Contact::~Contact() {

}

static inline  string input(string prompt) {
    string line;
    cout << prompt << endl;
    if (!getline(cin, line))
        exit(0);
    if (line.find_first_not_of(" ") == string::npos) {
        cout << "\033[1;48;2;255;255;255;38;2;255;0;0mField should not be empty\033[0m" << endl;
        return input(prompt);
    }

    return line;
}

void Contact::create_contact() {
    this->first_name = input("\033[1;48;2;255;255;255;38;2;45;18;193mFirst name :\033[0m");
    this->last_name = input("\033[1;48;2;255;255;255;38;2;45;18;193mLast name :\033[0m");
    this->nickname = input("\033[1;48;2;255;255;255;38;2;45;18;193mNickname :\033[0m");
    this->phone_number = input("\033[1;48;2;255;255;255;38;2;45;18;193mPhone number :\033[0m");
    this->darkest_secret = input("\033[1;48;2;255;255;255;38;2;45;18;193mDarkest secret :\033[0m");
}

static inline string modif(string str) {
    int len = str.length();
    int size_bs = 10 - len;

    if (len > 10){
        str = str.substr(0, 9) + ".";
        return str;
    }
    string res(size_bs, ' ');
    res += str;
    return res;
}

const   string& Contact::get_first_name() const {
    return this->first_name;
}
const   string& Contact::get_last_name() const {
    return this->last_name;
}
const   string& Contact::get_nickname() const {
    return this->nickname;
}


void    Contact::put_contact() {
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193mFirst name:\033[0m\t\033[1;38;2;255;20;147m" << this->first_name << "\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193mLast name:\033[0m\t\033[1;38;2;255;20;147m" << this->last_name << "\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193mNickname:\033[0m\t\033[1;38;2;255;20;147m" << this->nickname  << "\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193mPhone Number:\033[0m\t\033[1;38;2;255;20;147m"<< this->phone_number << "\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193mDark Secret:\033[0m\t\033[1;38;2;255;20;147m" << this->darkest_secret << "\033[0m" << endl;
}

ostream& operator<<(ostream& os, const Contact& act) {
    os << "\033[1;48;2;255;255;255;38;2;0;0;0m|\033[0m" << GRAS << PINK << modif(act.get_first_name()) << RESET;
    os << "\033[1;48;2;255;255;255;38;2;0;0;0m|\033[0m" << GRAS << PINK << modif(act.get_last_name()) << RESET;
    os << "\033[1;48;2;255;255;255;38;2;0;0;0m|\033[0m" << GRAS << PINK << modif(act.get_nickname()) << RESET;
    return os;
}
