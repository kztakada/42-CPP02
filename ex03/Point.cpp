#include "Point.hpp"

// Constructors
Point::Point() : _x(Fixed()), _y(Fixed()) {}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

// Destructor
Point::~Point() {}

// Copy constructor
Point::Point(Point const &other) : _x(other._x), _y(other._y) {}

// Operator overload
Point &Point::operator=(Point const &other) {
    if (this != &other) {
        // _x and _y are const, so we cannot assign to them
        // this->_x = other._x;
        // this->_y = other._y;
        // Instead, we can only copy if we are initializing a new object
        // which is already done in the copy constructor
    }
    return *this;
}

bool Point::operator==(Point const &other) const {
    return this->_x == other._x && this->_y == other._y;
}

bool Point::operator!=(Point const &other) const { return !(*this == other); }

Point Point::operator+(Point const &other) const {
    return Point(this->_x + other._x, this->_y + other._y);
}

Point Point::operator-(Point const &other) const {
    return Point(this->_x - other._x, this->_y - other._y);
}

Point Point::operator*(Point const &other) const {
    return Point(this->_x * other._x, this->_y * other._y);
}

Point Point::operator/(Point const &other) const {
    return Point(this->_x / other._x, this->_y / other._y);
}

// -------------------------------------
// Public member functions

const Fixed &Point::getX() const { return this->_x; }

const Fixed &Point::getY() const { return this->_y; }
