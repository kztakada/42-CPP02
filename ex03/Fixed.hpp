#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
   public:
    Fixed();
    Fixed(int const raw);
    Fixed(float const raw);
    ~Fixed();
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);
    bool operator>(Fixed const &other) const;
    bool operator<(Fixed const &other) const;
    bool operator>=(Fixed const &other) const;
    bool operator<=(Fixed const &other) const;
    bool operator==(Fixed const &other) const;
    bool operator!=(Fixed const &other) const;
    Fixed operator+(Fixed const &other) const;
    Fixed operator-(Fixed const &other) const;
    Fixed operator*(Fixed const &other) const;
    Fixed operator/(Fixed const &other) const;
    Fixed &operator++();    // Prefix increment
    Fixed operator++(int);  // Postfix increment
    Fixed &operator--();    // Prefix decrement
    Fixed operator--(int);  // Postfix decrement

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);

   private:
    int _rawBits;
    static const int _numOfFractionalBits = 8;
};

// Global overload of the << operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif /* FIXED_HPP */