#include "Point.hpp"


Fixed fixed_abs(Fixed res) {
    if (res < 0)
        res = res * -1;
    return (res);
}

Fixed   getArea(Point const &a, Point const &b, Point const &c) {
    
    Fixed demi(0.5f);
    //cout << a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()) << endl;
    return (fixed_abs(a.getX() * (b.getY() - c.getY())
                    + b.getX() * (c.getY() - a.getY())
                    + c.getX() * (a.getY() - b.getY()))
                    * demi);
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point) {
    Fixed A(getArea(a,b,c));
    Fixed P_1(getArea(point,a,b));
    Fixed P_2(getArea(point,a,c));
    Fixed P_3(getArea(point,c,b));
    // cout << "A : " << A << endl;
    // cout << "P_1 : " << P_1 << endl;
    // cout << "P_2 : " << P_2 << endl;
    // cout << "P_3 : " << P_3 << endl;
    // cout << "sum : " << P_1 + P_2 + P_3 << endl;
    if (P_1 + P_2 + P_3 != A || P_1 == 0 || P_2 == 0 || P_3 == 0)
        return false;
    return true;
}
