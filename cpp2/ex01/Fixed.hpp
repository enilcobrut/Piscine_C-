#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
    public :
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const; 
        ~Fixed();
    private :
        int left;
        static const int right;
};

std::ostream& operator<<(std::ostream& os, const Fixed& act);