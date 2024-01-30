#include <iostream>
#include "Fixed.hpp"
int main( void ) {
    //test du sujet
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
    // //my test
    Fixed c(5);
    Fixed const d(6);
    cout << "c + d : " << c + d << endl;
    cout << "c - d : " << c - d << endl;
    cout << "c * d : " << c * d << endl;
    cout << "c / d : " << c / d << endl;
    cout << "c < d "; c < d ? cout << "True" << endl : cout << "False" << endl;
    cout << "c > d "; c > d ? cout << "True" << endl : cout << "False" << endl;
    cout << "c <= d "; c <= d ? cout << "True" << endl : cout << "False" << endl;
    cout << "c >= d "; c >= d ? cout << "True" << endl : cout << "False" << endl;
    cout << "c == d "; c == d ? cout << "True" << endl : cout << "False" << endl;
    cout << "c != d "; c != d ? cout << "True" << endl : cout << "False" << endl;
    return 0;
}