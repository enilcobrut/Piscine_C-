#include "Fixed.hpp"
#include <math.h>

const int Fixed::right = 8;

Fixed::Fixed() : left(0) {
    cout << "Default constructor called" << endl;

}

Fixed::Fixed(const Fixed &fixed) {
    cout << "Copy constructor called" << endl;
    *this = fixed;
}


Fixed::Fixed(const float f) {
    cout << "Float constructor called" << endl;
    this->left = roundf(f * (1 << this->right));
}

float Fixed::toFloat() const {
        return (float)(this->left) / (1 << this->right);
    }

int Fixed::toInt() const {
        return this->left >> this->right;
}

Fixed::Fixed(const int n) {
    cout << "Int constructor called" << endl;
    this->left = n << this->right;
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
    return this->left;
}

void Fixed::setRawBits(int const raw) {
    this->left = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& act) {
    return (os << act.toFloat());
}
