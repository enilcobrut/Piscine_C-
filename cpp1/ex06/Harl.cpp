#include "Harl.hpp"

using std::string;

Harl::Harl() {

}

Harl::~Harl() {

}


void    Harl::complain(string level) {
    if (level.empty()) {
        cout << "string is empty" << endl;
        return ;
    }
    string result[4];
    result[0] = "DEBUG";
    result[1] = "INFO";
    result[2] = "WARNING";
    result[3] = "ERROR";
    int filter = -1;
    for (int i=0;i<4;i++) {
        if (result[i] == level)
            filter = i;
    }
    switch (filter)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break ;
        default:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
    }
}

void Harl::debug(void) {
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}
void Harl::info(void) {
    cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << endl;
}
void Harl::warning(void) {
    cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << endl;
}
void Harl::error(void) {
    cout << "This is unacceptable ! I want to speak to the manager now." << endl;
}