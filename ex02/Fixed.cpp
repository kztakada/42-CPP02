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
    // std::cout << "Copy constructor called" << std::endl;
    this->operator=(other);
}

// Operator overload
Fixed &Fixed::operator=(Fixed const &other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(Fixed const &other) const {
    return this->_rawBits > other.getRawBits();
}

bool Fixed::operator<(Fixed const &other) const {
    return this->_rawBits < other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const {
    return this->_rawBits >= other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const {
    return this->_rawBits <= other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const {
    return this->_rawBits == other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const {
    return this->_rawBits != other.getRawBits();
}

Fixed Fixed::operator+(Fixed const &other) const {
    Fixed result;
    result.setRawBits(this->_rawBits + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const &other) const {
    Fixed result;
    result.setRawBits(this->_rawBits - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const &other) const {
    long long long_result = static_cast<long long>(this->_rawBits) *
                            static_cast<long long>(other.getRawBits()) /
                            static_cast<long long>(1 << _numOfFractionalBits);
    Fixed result;
    result.setRawBits(static_cast<int>(long_result));
    return result;
}

Fixed Fixed::operator/(Fixed const &other) const {
    long long long_result =
        (static_cast<long long>(this->_rawBits) *
            static_cast<long long>(1 << _numOfFractionalBits)) /
        static_cast<long long>(other.getRawBits());
    Fixed result;
    result.setRawBits(static_cast<int>(long_result));
    return result;
}

// Prefix increment
Fixed &Fixed::operator++() {
    this->_rawBits++;
    return *this;
}

// Postfix increment
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

// Prefix decrement
Fixed &Fixed::operator--() {
    this->_rawBits--;
    return *this;
}

// Postfix decrement
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
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

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    return (a > b) ? a : b;
}

// Global overload of the << operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}