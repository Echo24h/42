#include "Point.hpp"

Fixed calcTriArea(Point a, Point b, Point c) {
    Fixed tmp = (a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() * a.getY())) + (c.getX() * (a.getY() - b.getY()));
    Fixed tmp = a.getX() + b.getX();
    std::cout << tmp << std::endl;
    exit(0);
    (void)c;
    if (tmp < Fixed(0)) {
        tmp = tmp * -1;
    }
    return (Fixed(0.5f) * tmp);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    (void)a;
    (void)b;
    (void)c;
    (void)point;
    return (true);
}
