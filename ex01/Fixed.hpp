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

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

   private:
    int _rawBits;
    static const int _numOfFractionalBits = 8;
};

// Global overload of the << operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif /* FIXED_HPP */