#include "Point.hpp"

Point::Point() : x(0), y(0){

}

Point& Point::operator=(const Point &p) {
    if (this != &p) {
        cout << "Constant member should not be changed with an = operator" << endl;
    }
    return *this; 
}


Point::Point(const Point &point) {
    *this = point;
}
Point::Point(const Fixed &f1, const Fixed &f2) : x(f1), y(f2) {

}

Point::~Point() {

}

Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}
