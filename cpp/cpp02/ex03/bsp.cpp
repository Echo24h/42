#include "Point.hpp"

static Fixed calcTriArea(Point a, Point b, Point c) {
    Fixed tmp = (a.getX() * (b.getY() - c.getY()))
        + (b.getX() * (c.getY() - a.getY()))
        + (c.getX() * (a.getY() - b.getY()));
    if (tmp < Fixed(0)) {
        tmp = tmp * -1;
    }
    return (tmp / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = calcTriArea(a, b, c);
    Fixed areaABP = calcTriArea(a, b, point);
    Fixed areaBCP = calcTriArea(b, c, point);
    Fixed areaACP = calcTriArea(a, c, point);

    return ((areaABC < areaABP + areaACP + areaBCP) ? false : true);
}
