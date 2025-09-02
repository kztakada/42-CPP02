#include <iostream>

#include "Fixed.hpp"

void testValue(float value) {
    Fixed fixed(value);
    std::cout << "---" << std::endl;
    std::cout << "Original: " << value << std::endl;
    std::cout << "Raw bits: " << fixed.getRawBits() << std::endl;
    std::cout << "toInt(): " << fixed.toInt() << std::endl;
    std::cout << "Back to float: " << fixed.toFloat() << std::endl;
    std::cout << "---" << std::endl;
}

int main(void) {
    {
        Fixed a;
        Fixed const b(10);
        Fixed const c(42.42f);
        Fixed const d(b);
        a = Fixed(1234.4321f);
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    }
    std::cout << "----------------" << std::endl;
    {
        testValue(-0.75f);
        testValue(-1.25f);
        testValue(-2.99f);
    }
    return 0;
}