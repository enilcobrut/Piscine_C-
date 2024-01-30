#include "Brain.hpp"
#include <math.h>
#include <time.h>

using std::to_string;


Brain &Brain::operator=(const Brain &res) {
    if (this != &res) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = res.ideas[i];
        }
    }
    return *this;
}



Brain::Brain() {
    cout << ORANGE << "Brain constructor" << RESET << endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "Idea #" + to_string(i) + ": " + to_string(rand());
    }
}


Brain::Brain(const Brain &copy) {
    cout << ORANGE << "Copy Brain constructor"<< RESET << endl;
    *this = copy;
}

string Brain::getIdea(const int idx) const {
    return this->ideas[idx];
}

void Brain::setIdea(const string idea, const int idx)  {
    this->ideas[idx] = idea;
}




Brain::~Brain() {
    cout << VIOLET << "Brain destructor"<< RESET << endl;
}