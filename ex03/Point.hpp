#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
   public:
    Point();
    Point(Fixed const &x, Fixed const &y);
    Point(float const x, float const y);
    ~Point();
    Point(Point const &other);
    Point &operator=(Point const &other);
    bool operator==(Point const &other) const;
    bool operator!=(Point const &other) const;
    Point operator+(Point const &other) const;
    Point operator-(Point const &other) const;
    Point operator*(Point const &other) const;
    Point operator/(Point const &other) const;

    const Fixed &getX() const;
    const Fixed &getY() const;

   private:
    const Fixed _x;
    const Fixed _y;
};

#endif /* POINT_HPP */