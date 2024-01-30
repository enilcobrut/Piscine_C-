#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->index = 0;
    this->size = 0;
}

PhoneBook::~PhoneBook() {

}

//fonction = methode de la classe phonebook
void PhoneBook::loop() {
    string ligne;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m┏━━━━━━━━━━━━━━━━PHONEBOOK━━━━━━━━━━━━━━━━━┓\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m┃        Welcome to the Phone Book!        ┃\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m┃        You can ADD, to ADD someone       ┃\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m┃      You can SEARCH, to SEARCH someone   ┃\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m┃           You can EXIT, to EXIT          ┃\033[0m" << endl;
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m" << endl;
    while (getline(cin, ligne)) {
        if (ligne == "ADD")
            this->add();
        if (ligne == "SEARCH")
            this->search();
        if (ligne == "EXIT")
            break;
    }
}

void PhoneBook::add() {
    this->repertoire[this->index].create_contact();
    ++this->index;
    ++this->size;
    this->index %= 8;
    this->size = std::min(this->size, 8);
}


//on redefinie l'operateur << pour dire au compilateur comment afficher la classe
//contact pour cela on redirige le flux de sortie dans os

ostream& operator<<(ostream& os, const Contact& act);

ostream& operator<<(ostream& os, const PhoneBook& act) {
    for (int i = 0; i < act.getSize(); i++)
    {
        cout << "         " << PINK << GRAS << i + 1 << RESET;
        os << act.getRepertoire()[i] << endl;
    }
    return os;

}

int PhoneBook::getIndex() const {
        return this->index;
    }

int PhoneBook::getSize() const {
    return this->size;
}

const Contact* PhoneBook::getRepertoire() const {
    return this->repertoire;
}


static inline  string get_index(string prompt) {
    string line;
    cout << prompt << endl;
    if (!getline(cin, line))
        exit(0);
    if (line == "")
        return get_index(prompt);
    return line;
    
}


//on imprime l objet lui meme et pas son adresse
// this -> pointeur sur l'instance de l'objet

void PhoneBook::search() {
    int idx;
    if (!this->size) {
        cout << "\033[1;48;2;255;255;255;38;2;255;0;0mThere is no contact\033[0m" << endl;
        return ;
    }
    cout << "\033[1;48;2;255;255;255;38;2;45;18;193m     index\033[0m\033[1;48;2;255;255;255;38;2;0;0;0m|\033[0m\033[1;48;2;255;255;255;38;2;45;18;193mFirst name\033[0m\033[1;48;2;255;255;255;38;2;0;0;0m|\033[0m\033[1;48;2;255;255;255;38;2;45;18;193m Last name\033[0m\033[1;48;2;255;255;255;38;2;0;0;0m|\033[0m\033[1;48;2;255;255;255;38;2;45;18;193m  nickname\033[0m"  << endl;
    cout << *this << endl;
    while (1) {
        string res = get_index("\033[1;48;2;255;255;255;38;2;45;18;193mEnter an index :\033[0m");
        idx = atoi(res.c_str());
        if (idx > 0 && idx <= this->size)
            break ;
        cout << "\033[1;48;2;255;255;255;38;2;255;0;0mEnter a valid index please between 1 and " << this->size << "\033[0m" << endl;
    }
    this->repertoire[idx - 1].put_contact();
}
