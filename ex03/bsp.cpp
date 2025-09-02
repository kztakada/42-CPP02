#include "Fixed.hpp"
#include "Point.hpp"

static Fixed crossProduct(Point const p1, Point const p2, Point const p3) {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
           (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed crossAB = crossProduct(a, b, point);
    Fixed crossBC = crossProduct(b, c, point);
    Fixed crossCA = crossProduct(c, a, point);

    // 全て同じ符号（または0）なら内部または境界上
    bool isOnEdge =
        (crossAB == Fixed(0)) || (crossBC == Fixed(0)) || (crossCA == Fixed(0));
    if (isOnEdge)
        return false;

    bool isLeftSide =
        (crossAB > Fixed(0)) && (crossBC > Fixed(0)) && (crossCA > Fixed(0));
    bool isRightSide =
        (crossAB < Fixed(0)) && (crossBC < Fixed(0)) && (crossCA < Fixed(0));
    if (isRightSide || isLeftSide)
        return true;
    return false;
}
