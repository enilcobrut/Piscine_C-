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
    void (Harl::*ptr[4])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };
     void (Harl::*ptr1)(void) = NULL;
    for (int i = 0; i < 4; i++) {
        if (result[i] == level)
            ptr1 = ptr[i];
    }
    if (!ptr1) {
        cout << "error fct is null" << endl;
    }
    else
        (this->*ptr1)();
}

void Harl::debug(void) {
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}
void Harl::info(void) {
    cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << endl;
}
void Harl::warning(void) {
    cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << endl;
}
void Harl::error(void) {
    cout << "This is unacceptable ! I want to speak to the manager now." << endl;
}