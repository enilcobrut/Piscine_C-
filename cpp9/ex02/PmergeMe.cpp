#include "PmergeMe.hpp"
#include <stdlib.h>

PmergeMe::PmergeMe(const PmergeMe &copy) : numbers(copy.numbers) {
        this->a = copy.a;
        this->b = copy.b;
}
PmergeMe::PmergeMe(int numbers) : numbers(numbers) , a(NULL), b(NULL) {

}
PmergeMe::PmergeMe(PmergeMe *a, PmergeMe *b) {
    this->a = a;
    this->b = b;
    this->numbers = a->getNumber();
}

int PmergeMe::getNumber() const {
    return this->numbers;
}

PmergeMe *PmergeMe::getA() const {
    return this->a;
}

PmergeMe *PmergeMe::getB() const {
    return this->b;
}



void PmergeMe::swap(PmergeMe *a, PmergeMe *b) {
    PmergeMe *tmp = a;
    a = b;
    b = tmp;
}

bool PmergeMe::operator>(const PmergeMe& lhs) {
   return (this->getNumber() > lhs.getNumber());
}

bool PmergeMe::operator<(const PmergeMe& lhs) {
   return (this->getNumber() < lhs.getNumber());
}

PmergeMe &PmergeMe::operator=(const PmergeMe &res) {
    if (this != &res) {
        this->numbers = res.numbers;
        delete this->a;
        this->a = res.a;
        delete this->b;
        this->b =res.b;
    }
    return *this;
}
PmergeMe::~PmergeMe()  {
}