#include "PmergeMe.hpp"


#include <iostream>
#include <deque>
#include <math.h>
#include <algorithm>
#include <sys/time.h>


void print_time(timeval start, timeval end, size_t size, string container) {
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = (seconds * 1e6 + microseconds) / 1000;

    cout << "Time to process a range of " << size << " elements with std::" << container << " : " << std::fixed << elapsed << " ms" << endl;
}


template<typename Container>
void printContainer(const Container& cont) {
    for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << (*it)->getNumber() << " ";
    }
    std::cout << std::endl;
}


struct PmergeMeComparator {
    bool operator()(PmergeMe* lhs, PmergeMe* rhs) const {
        return lhs->getNumber() < rhs->getNumber();
    }
};

template <typename Container>
void reserve_if_possible(Container&, std::size_t)
{
}

template <typename T>
void reserve_if_possible(std::vector<T>& container, std::size_t size)
{
    container.reserve(size);
}


template <typename Container>
void sort(Container &A) {
    if (A.size() == 1){
        return;
    }
    
    Container P;
    PmergeMe *tp;

    reserve_if_possible(P, A.size() / 2);

    for (size_t i = 0; i < A.size() / 2; i++) {
        if (*A[2 * i] > *A[2 * i + 1]) {
            tp = new PmergeMe(A[2*i], A[2*i + 1]);
        }
        else {
            tp = new PmergeMe(A[2*i + 1], A[2*i]);
        }
        P.push_back(tp);
    }

    sort(P);

    for (size_t i = 0; i < P.size(); i++) {
        A[i] = P[i]->getA();
    }
    for (size_t i = 0; i <  P.size(); i++) {
        A[P.size() + i] = P[i]->getB();
    }

    unsigned long batchLimit = -1;

    for (size_t k = 0, batchBegin = P.size(); batchBegin < A.size(); k++) {

        
        unsigned long batchSize = (pow(2, k + 1) + pow(-1, k)) / 3;
        if (batchSize + batchBegin >= A.size())
            batchSize = A.size() - batchBegin;

        unsigned long batchEnd = batchBegin + batchSize - 1;        
        batchLimit += batchSize;
    
            for (size_t i = 0; i < batchSize; i++) {
                size_t pos = std::lower_bound(A.begin(), A.begin() + batchLimit, A[batchEnd], PmergeMeComparator()) - A.begin();
                PmergeMe *tmp = A[batchEnd];
                for (size_t j = batchEnd; j > pos; j--) {
                    A[j] = A[j - 1];
                }
                A[pos] = tmp;
        }
        batchLimit += batchSize;
        batchBegin += batchSize;

    }

    for (unsigned long i = 0; i < P.size(); i++)
       delete P[i];
}




int main(int ac, char **av) {
    timeval start, endVector, endDeque;
    gettimeofday(&start, NULL);
    if (ac == 1) {
        std::cout << RED << "USAGE : " RESET << "./PmergeMe $(jot -r 20000 0 10000 | tr '\\n' ' ')" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<PmergeMe *> vector_;
    std::deque<PmergeMe *> deque_;

    vector_.reserve((ac - 1));
     for (int i = 1; i < ac; ++i) {
        int n = std::atoi(av[i]);
        if ((av[i][0] != '0' && n == 0 )|| n < 0) {
            std::cout << RED << "BAD ARGUMENT ERROR : "<< RESET<< "["  << RED << av[i] << RESET <<"] must be a positive integer value" << RESET << std::endl;
            exit(EXIT_FAILURE);   
        }
        PmergeMe* tp = new PmergeMe(n);
        vector_.push_back(tp);
        deque_.push_back(tp);
    }

    std::cout << "Before: ";
    printContainer(vector_);
    sort(vector_);
    gettimeofday(&endVector, NULL);
    sort(deque_);
    gettimeofday(&endDeque, NULL);
    std::cout << "After: ";
    printContainer(vector_);
    
    print_time(start, endVector, ac - 1, "vector");
    print_time(start, endDeque, ac - 1, "deque");

    //system("leaks Pmerge");
    return (EXIT_SUCCESS);
}


/*TO CHECK IF THE LIST IS SORTED :

./PmergeMe $(jot -r 20000 0 10000 | tr '\n' ' ') | awk '/After/ {for(i=3; i<=NF; i++) if ($i ~ /^[0-9]+$/) printf $i " "; print ""}' | python3.11 -c "import sys; liste = list(map(int, sys.stdin.read().split())); print(liste == sorted(liste))"

*/