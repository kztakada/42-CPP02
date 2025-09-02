#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
   public:
    Fixed();
    ~Fixed();
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);

    int getRawBits() const;
    void setRawBits(int const raw);

   private:
    int _rawBits;
    static const int _numOfFractionalBits = 8;
};

#endif /* FIXED_HPP */