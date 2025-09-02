#include "Fixed.hpp"

#include <cmath>
#include <iostream>

// Constructors
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw) {
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = raw << _numOfFractionalBits;
}

Fixed::Fixed(float const raw) {
    std::cout << "Float constructor called" << std::endl;

    this->_rawBits = roundf(raw * (1 << _numOfFractionalBits));
}

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// Copy constructor
Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(other);
}

// Operator overload
Fixed &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

// -------------------------------------
// Public member functions
int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

int Fixed::toInt(void) const {
    return this->_rawBits / (1 << _numOfFractionalBits);
}
// return _rawBits >> _numOfFractionalBits
// value is rounded towards minus infinity (it should be rounded towards zero)

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_rawBits) / (1 << _numOfFractionalBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}