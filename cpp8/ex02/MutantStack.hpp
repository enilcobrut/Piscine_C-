#pragma once

#include <iostream>
#include <stack>
#define RESET "\033[0m"
#define PINK "\033[1;38;2;230;100;120m"
#define ORANGE "\033[1;38;2;255;187;54m"
#define GREEN "\033[1;38;2;;196;0;128m"
#define BLUE "\033[1;38;2;188;238;255m"
#define RED "\033[1;38;2;254;73;73m"
#define GRAS "\033[1m"

using std::cout;
using std::endl;
using std::string;
template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {};
    MutantStack(const MutantStack &copy) {
        *this = copy;
    }
    MutantStack &operator=(MutantStack const &res) {
        (void)res;
        return *this;
    }
    virtual ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const {
        return this->c.begin();
    }
    const_iterator end() const {
        return this->c.end();
    }
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    reverse_iterator rend() const {
        return this->c.rend();
    }
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator crbegin() const {
        return this->c.crbegin();
    }
    const_reverse_iterator crend() const {
        return this->c.crend();
    }
};
