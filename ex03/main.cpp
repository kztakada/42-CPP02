#include <cassert>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

struct triangle {
    Point a;
    Point b;
    Point c;
};

bool testBsp(triangle const &tri, Point const &point) {
    return bsp(tri.a, tri.b, tri.c, point);
}

void printTriangle(const Point a, const Point b, const Point c, const Point p) {
    // get min and max of x and y
    long minX = std::min(std::min(a.getX(), b.getX()), c.getX()).getRawBits();
    long maxX = std::max(std::max(a.getX(), b.getX()), c.getX()).getRawBits();
    long minY = std::min(std::min(a.getY(), b.getY()), c.getY()).getRawBits();
    long maxY = std::max(std::max(a.getY(), b.getY()), c.getY()).getRawBits();

    // get size of the triangle
    long width = maxX - minX;
    long height = maxY - minY;
    long size = std::max(width, height);
    if (size == 0)
        size = 1;

    // convert to 10x10 grid
    int ax = (a.getX().getRawBits() - minX) * 10 / size;
    int ay = (a.getY().getRawBits() - minY) * 10 / size;
    int bx = (b.getX().getRawBits() - minX) * 10 / size;
    int by = (b.getY().getRawBits() - minY) * 10 / size;
    int cx = (c.getX().getRawBits() - minX) * 10 / size;
    int cy = (c.getY().getRawBits() - minY) * 10 / size;
    int px = (p.getX().getRawBits() - minX) * 10 / size;
    int py = (p.getY().getRawBits() - minY) * 10 / size;

    // print triangle
    bool printed = false;
    for (int y = 10; y >= 0; y--) {
        for (int x = 0; x <= 10; x++) {
            if (!printed)
                std::cout << " ";
            if (x == ax && y == ay) {
                std::cout << "A";
            } else if (x == bx && y == by) {
                std::cout << "B";
            } else if (x == cx && y == cy) {
                std::cout << "C";
            } else if (x == px && y == py) {
                std::cout << "P";
                // if point is on the edge of the triangle
            } else if (((y - ay) * (bx - ax) == (by - ay) * (x - ax)) &&
                       x >= std::min(ax, bx) && x <= std::max(ax, bx) &&
                       y >= std::min(ay, by) && y <= std::max(ay, by)) {
                std::cout << ".";
            } else if (((y - by) * (cx - bx) == (cy - by) * (x - bx)) &&
                       x >= std::min(bx, cx) && x <= std::max(bx, cx) &&
                       y >= std::min(by, cy) && y <= std::max(by, cy)) {
                std::cout << ".";
            } else if (((y - cy) * (ax - cx) == (ay - cy) * (x - cx)) &&
                       x >= std::min(cx, ax) && x <= std::max(cx, ax) &&
                       y >= std::min(cy, ay) && y <= std::max(cy, ay)) {
                std::cout << ".";
            } else {
                std::cout << " ";
            }
            if ((x == ax && y == ay) + (x == bx && y == by) +
                    (x == cx && y == cy) + (x == px && y == py) >
                1) {
                std::cout << "*";
                printed = true;
            } else {
                printed = false;
            }
        }
        std::cout << std::endl;
    }
}

void printTriangle(const triangle &tri, const Point &p) {
    printTriangle(tri.a, tri.b, tri.c, p);
}

int main() {
    triangle tri_int1 = {Point(5, 0), Point(0, 0), Point(0, 5)};
    triangle tri_int2 = {Point(3, 10), Point(7, -2), Point(-4, 1)};
    triangle tri_float1 = {
        Point(0.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 5.0f)};
    triangle tri_float2 = {
        Point(3.23f, 10.8f), Point(7.5f, -2.3f), Point(-4.2f, 1.1f)};

    // Test case 1: Point inside the triangle
    assert(testBsp(tri_int1, Point(1, 1)) == true);
    assert(testBsp(tri_int2, Point(3, 3)) == true);
    assert(testBsp(tri_float1, Point(1.0f, 1.0f)) == true);
    assert(testBsp(tri_float2, Point(1.0f, 1.0f)) == true);
    printTriangle(tri_int2, Point(3, 3));
    // printTriangle(tri_float2, Point(1.0f, 1.0f));

    // Test case 2: Point outside the triangle
    assert(testBsp(tri_int1, Point(6, 6)) == false);
    assert(testBsp(tri_int2, Point(8, 8)) == false);
    assert(testBsp(tri_float1, Point(6.0f, 6.0f)) == false);
    assert(testBsp(tri_float2, Point(10.0f, 10.0f)) == false);
    assert(testBsp(tri_float2, Point(3.23f, 10.81f)) == false);

    // Test case 3: Point on the edge of the triangle
    assert(testBsp(tri_int1, Point(0, 0)) == false);
    assert(testBsp(tri_int1, Point(1, 0)) == false);
    assert(testBsp(tri_int1, Point(0, 1)) == false);
    assert(testBsp(tri_int2, Point(3, 10)) == false);
    assert(testBsp(tri_int2, Point(7, -2)) == false);
    assert(testBsp(tri_int2, Point(-4, 1)) == false);
    assert(testBsp(tri_float1, Point(0.0f, 0.0f)) == false);
    assert(testBsp(tri_float1, Point(1.0f, 0.0f)) == false);
    assert(testBsp(tri_float1, Point(0.0f, 1.0f)) == false);
    assert(testBsp(tri_float2, Point(3.23f, 10.8f)) == false);

    return 0;
}
