#include "Fixed.hpp"

const int Fixed::right = 8;

Fixed::Fixed() : left(0) {
    cout << "Default constructor called" << endl;

}

Fixed::Fixed(const Fixed &fixed) {
    cout << "Copy constructor called" << endl;
   *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    cout << "Copy assignment operator called" << endl;
    if (this !=  &fixed) 
        this->left = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const {
    cout << "getRawBits function called" << endl;
    return this->left;
}

void Fixed::setRawBits(int const raw) {
    cout << "setRawBits function called" << endl;
    this->left = raw;
}
