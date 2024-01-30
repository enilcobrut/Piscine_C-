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
        bool operator>(const Fixed &Right)const;
        bool operator<(const Fixed &Right)const;
        bool operator>=(const Fixed &Right)const;
        bool operator<=(const Fixed &Right)const;
        bool operator==(const Fixed &Right)const;
        bool operator!=(const Fixed &Right)const;
        Fixed operator+(const Fixed &Right)const;
        Fixed operator-(const Fixed &Right)const;
        Fixed operator*(const Fixed &Right)const;
        Fixed operator/(const Fixed &Right)const;
        Fixed &operator++(void);
        Fixed operator++(const int Right);
        Fixed &operator--(void);
        Fixed operator--(const int Right);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);
        ~Fixed();
    private :
        int left;
        static const int right;
};



std::ostream& operator<<(std::ostream& os, const Fixed& act);