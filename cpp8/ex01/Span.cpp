#include "Span.hpp"
#include <algorithm>
#include <cmath>

Span::Span() {

}

Span::Span(const Span &copy) : N(copy.N), count(copy.count), tab(new int[N]) {
    for (size_t i = 0; i < N; i++)
        this->tab[i] = copy.tab[i];
}

Span::Span(unsigned int N) : N(N), count(0), tab(new int[N]) {

}

Span &Span::operator=(const Span &res) {
    if (this != &res) {
        this->count = res.count;
        this->N = res.N;
        delete [] tab;
        this->tab = new int[N];
        for (size_t i = 0; i < this->count; i++)
            this->tab[i] = res.tab[i];
    }
    return *this;
}

void Span::addNumber(int n) {
    if (this->count >= this->N)
        throw std::out_of_range("Span is already full");
    this->tab[this->count++] = n;
}


unsigned int Span::shortestSpan() {
    if (this->count <= 1)
       throw std::out_of_range("Cannot find span with less than two numbers");
    int tp[this->N];
    std::copy(tab, tab + this->N, tp);
    std::sort(tp, tp + N);
    unsigned int min_dist = tp[1] - tp[0];
    for (unsigned int i = 2; i < this->count; i++)  
        min_dist = std::min(static_cast<unsigned int>(min_dist), static_cast<unsigned int>(tp[i] - tp[i - 1]));
    return min_dist;
}

unsigned int Span::longestSpan() {
    if (this->count <= 1)
       throw std::out_of_range("Cannot find span with less than two numbers");
    int tp[this->count];
    std::copy(tab, tab + this->count, tp);
    std::sort(tp, tp + this->count);
    return (tp[this->count - 1] - tp[0]);
}

Span::~Span() {
    delete []tab;
}