#include "Fixed.hpp"
#include <math.h>

const int Fixed::right = 8;

Fixed::Fixed() : left(0) {

}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed::Fixed(const float f) {
    this->left = roundf(f * (1 << this->right));
}

float Fixed::toFloat() const {
        return (float)(this->left) / (1 << this->right);
}
int Fixed::toInt() const {
        return this->left >> this->right;
}

Fixed::Fixed(const int n) {
    this->left = n << this->right;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this !=  &fixed) 
        this->left = fixed.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &Right) const {
    return (this->toFloat() > Right.toFloat());
}
bool Fixed::operator<(const Fixed &Right) const {
    return this->toFloat() < Right.toFloat();
}
bool Fixed::operator>=(const Fixed &Right) const {
    return this->toFloat() >= Right.toFloat();
}
bool Fixed::operator<=(const Fixed &Right) const {
    return this->toFloat()<= Right.toFloat();
}
bool Fixed::operator==(const Fixed &Right) const {
    return this->toFloat() == Right.toFloat();
}
bool Fixed::operator!=(const Fixed &Right) const {
    return this->toFloat() != Right.toFloat();
}

Fixed Fixed::operator+(const Fixed &Right) const {
   return (this->toFloat() + Right.toFloat());
}

Fixed Fixed::operator-(const Fixed &Right) const {
   return (this->toFloat() - Right.toFloat());
}

Fixed Fixed::operator*(const Fixed &Right) const {
    return (this->toFloat() * Right.toFloat());
}
Fixed Fixed::operator/(const Fixed &Right) const {
    return (this->toFloat() / Right.toFloat());
}

Fixed &Fixed::operator++(void) {
    ++this->left;
    return*this;
}

Fixed Fixed::operator++(const int) {
    Fixed cpy(*this);
    ++(*this);
    return (cpy);
}

Fixed &Fixed::operator--(void) {
    --this->left;
    return*this;
}

Fixed Fixed::operator--(const int) {
    //(void)Right;
    Fixed cpy(*this);
    --(*this);
    return (cpy);
}

Fixed::~Fixed() {
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


Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return (f1 < f2) ? f1 : f2;
}
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return (f1 < f2) ? f1 : f2;
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return (f1 > f2) ? f1 : f2;
} 
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return (f1 > f2) ? f1 : f2;
}
