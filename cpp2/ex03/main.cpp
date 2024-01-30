#include "Point.hpp"
#include <iostream>

using namespace std;

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

void printPoints(Point const &a, Point const &b, Point const &c, Point const &p) {
    cout << "Points:" << endl;
    cout << "a: (" << a.getX() << ", " << a.getY() << ")" << endl;
    cout << "b: (" << b.getX() << ", " << b.getY() << ")" << endl;
    cout << "c: (" << c.getX() << ", " << c.getY() << ")" << endl;
    cout << "p: (" << p.getX() << ", " << p.getY() << ")" << endl;
}

void printResult(bool result) {
    if (result)
        cout << "Le point se trouve dans le triangle." << endl;
    else
        cout << "Le point ne se trouve pas dans le triangle." << endl;
}

void printTriangle(Point const &a, Point const &b, Point const &c, Point const &p) {
    int min_x = min(min(min(a.getX().toInt(), b.getX().toInt()), min(c.getX().toInt(), p.getX().toInt())), 0);
    int max_x = max(max(max(a.getX().toInt(), b.getX().toInt()), max(c.getX().toInt(), p.getX().toInt())), 0);
    int min_y = min(min(min(a.getY().toInt(), b.getY().toInt()), min(c.getY().toInt(), p.getY().toInt())), 0);
    int max_y = max(max(max(a.getY().toInt(), b.getY().toInt()), max(c.getY().toInt(), p.getY().toInt())), 0);

    cout << "Espace de coordonnées : X(" << min_x << ", " << max_x << "), Y(" << min_y << ", " << max_y << ")" << endl;
    for (int y = max_y + 1; y >= min_y - 1; --y) {
        for (int x = min_x - 1; x <= max_x + 1; ++x) {
            if (x == a.getX().toInt() && y == a.getY().toInt()) {
                cout << "a";
            } else if (x == b.getX().toInt() && y == b.getY().toInt()) {
                cout << "b";
            } else if (x == c.getX().toInt() && y == c.getY().toInt()) {
                cout << "c";
            } else if (x == p.getX().toInt() && y == p.getY().toInt()) {
                cout <<  "p";
            } else if (x == 0 && y == 0) {
                cout << "+";
            } else if (x == 0) {
                cout << "|";
            } else if (y == 0) {
                cout << "-";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    Point const a(10, 20);
    Point const b(-15.3f, 16.0f);
    Point const c(17.0f, -5.0f);
    Point const p(8.40f, 18.0f);


    bool result = bsp(a, b, c, p);

    printPoints(a, b, c, p);
    printResult(result);
    printTriangle(a, b, c, p);


    return 0;
}