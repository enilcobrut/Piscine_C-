#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
    public :
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
    private :
        int left;
        static const int right;
};
