#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using std::set;
using std::srand;
int main() {

    cout << endl;
	cout <<  GRAS << "------------------ SIMPLE TEST ------------------" << RESET << endl << endl;

    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        cout << BLUE << "Shortest Span : " << RESET << sp.shortestSpan() << endl;
        cout << BLUE << "Longest Span : "<< RESET << sp.longestSpan() << endl;
    }
    catch (const std::exception& e) {
        cout << RED << "Error: " << RESET << e.what()  << std::endl;
    }
    cout << endl;
	cout <<  GRAS << "------------------ LITLE SPAN RANDOM ------------------" << RESET << endl << endl;
    srand(static_cast<unsigned int>(std::time(NULL)));
    Span spanRand(100);

    set<int> unique;
    while (unique.size() < 100) {
        unsigned int num = std::rand() % 500000;
        if (unique.find(num) == unique.end()) {
            unique.insert(num);
        }
    }
    spanRand.addRange(unique.begin(), unique.end());

    try {
        unsigned int shortest = spanRand.shortestSpan();
        unsigned int longest = spanRand.longestSpan();
        std::cout << BLUE << "Shortest span: " << RESET << shortest << std::endl;
        std::cout << BLUE << "Longest span: " << RESET << longest << std::endl;
    }
    catch (const std::exception& e) {
        cout << RED << "Error: " << RESET << e.what()  << std::endl;
    }

    cout << endl;
	cout <<  GRAS << "------------------ BIG SPAN RANDOM ------------------" << RESET << endl << endl;
    
    Span span(100000);

    set<int> unique_nums;
    while (unique_nums.size() < 100000) {
        unsigned int num = std::rand() % 10000000;
        if (unique_nums.find(num) == unique_nums.end()) {
            unique_nums.insert(num);
        }
    }

    span.addRange(unique_nums.begin(), unique_nums.end());

    try {
        unsigned int shortest = span.shortestSpan();
        unsigned int longest = span.longestSpan();
        std::cout << BLUE << "Shortest span: " << RESET << shortest << std::endl;
        std::cout << BLUE << "Longest span: " << RESET << longest << std::endl;
    }
    catch (const std::exception& e) {
        cout << RED << "Error: " << RESET << e.what()  << std::endl;
    }

    cout << endl;
	cout <<  GRAS << "------------------ ERROR CHECK ------------------" << RESET << endl << endl;

    try {
        Span sp = Span(0);
        unsigned int shortest = sp.shortestSpan();
        unsigned int longest = sp.longestSpan();
        cout << BLUE << "Shortest Span : " << RESET << shortest << endl;
        cout << BLUE << "Longest Span : "<< RESET << longest << endl;


    }
    catch (const std::exception& e) {
        cout << RED << "Error: " << RESET << e.what()  << std::endl;
    }


    try {
        Span sp = Span(2);
        sp.addNumber(20);
        sp.addNumber(21);
        sp.addNumber(20);
        unsigned int shortest = sp.shortestSpan();
        unsigned int longest = sp.longestSpan();
        cout << BLUE << "Shortest Span : " << RESET << shortest << endl;
        cout << BLUE << "Longest Span : "<< RESET << longest << endl;


    }
    catch (const std::exception& e) {
        cout << RED << "Error: " << RESET << e.what()  << std::endl;
    }

    return 0;
}