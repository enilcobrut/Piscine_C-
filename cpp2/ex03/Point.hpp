#include <iostream>
#include "Fixed.hpp"

class Point {
    public :
        Point();
        Point(const Point &point);
        Point(const Fixed &f1, const Fixed &f2);
        Point &operator=(const Point &p);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
        
    private :
        const Fixed x;
        const Fixed y;

};

std::ostream& operator<<(std::ostream& os, const Point& act);