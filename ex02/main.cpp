#include <cassert>
#include <cmath>
#include <iostream>

#include "Fixed.hpp"

void compareTests(Fixed large, Fixed small) {
    // Test comparison operators
    assert(large > small);
    assert(small < large);
    assert(large >= small);
    assert(small <= large);
    assert(large != small);
    assert(!(large == small));
    // std::cout << "Comparison tests passed." << std::endl;
}

void compareToEqualTests(Fixed equal1, Fixed equal2) {
    // Test comparison operators for equal values
    assert(!(equal1 > equal2));
    assert(!(equal1 < equal2));
    assert(equal1 >= equal2);
    assert(equal1 <= equal2);
    assert(equal1 == equal2);
    assert(!(equal1 != equal2));
    // std::cout << "Comparison to equal tests passed." << std::endl;
}

void intArithmeticTests(Fixed int_large, Fixed int_small, bool hasZero) {
    // Test arithmetic operators
    assert((int_large + int_small).toInt() ==
           (int_large.toInt() + int_small.toInt()));
    assert((int_large - int_small).toInt() ==
           (int_large.toInt() - int_small.toInt()));
    assert((int_large * int_small).toInt() ==
           (int_large.toInt() * int_small.toInt()));
    if (!hasZero) {
        assert((int_large / int_small).toInt() ==
               (int_large.toInt() / int_small.toInt()));
    }
    // std::cout << "Integer arithmetic tests passed." << std::endl;
}

void floatArithmeticTests(Fixed float_large, Fixed float_small, bool hasZero) {
    // Test arithmetic operators
    assert(fabs((float_large + float_small).toFloat() -
                (float_large.toFloat() + float_small.toFloat())) < 0.01f);
    assert(fabs((float_large - float_small).toFloat() -
                (float_large.toFloat() - float_small.toFloat())) < 0.01f);
    assert(fabs((float_large * float_small).toFloat() -
                (float_large.toFloat() * float_small.toFloat())) < 0.01f);
    if (!hasZero) {
        assert(fabs((float_large / float_small).toFloat() -
                    (float_large.toFloat() / float_small.toFloat())) < 0.01f);
    }
    // std::cout << "Float arithmetic tests passed." << std::endl;
    // std::cout << "Float Arithmetic Tests: " << float_large << " and "
    //           << float_small << std::endl;
    // std::cout << "Float addition: " << (float_large + float_small) <<
    // std::endl; std::cout << "Float subtraction: " << (float_large -
    // float_small)
    //           << std::endl;
    // std::cout << "Float multiplication: " << (float_large * float_small)
    //           << std::endl;
    // std::cout << "Float division: " << (float_large / float_small) <<
    // std::endl;
}

void incrementDecrementTests(Fixed value, Fixed delta) {
    // Test increment/decrement operators

    Fixed tmp = value;
    assert(++value - tmp == delta);
    tmp = value;
    assert(value++ == tmp);
    assert(value - tmp == delta);
    tmp = value;
    assert(--value == tmp - delta);
    tmp = value;
    assert(value-- == tmp);
    assert(value == tmp - delta);
    std::cout << "Increment/Decrement tests passed." << std::endl;
}

void testPlusIntegers(Fixed a, Fixed b) {
    a = Fixed(10);
    b = Fixed(3);
    compareTests(a, b);
    intArithmeticTests(a, b, false);
    assert(Fixed::min(a, b) == b);
    assert(Fixed::max(a, b) == a);
    const Fixed constA = a;
    const Fixed constB = b;
    assert(Fixed::min(constA, constB) == constB);
    assert(Fixed::max(constA, constB) == constA);
    b = Fixed(10);
    compareToEqualTests(a, b);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == a);
    const Fixed constA1 = a;
    const Fixed constB1 = b;
    assert(Fixed::min(constA1, constB1) == constA1);
    assert(Fixed::max(constA1, constB1) == constA1);
    a = Fixed(10);
    b = Fixed(0);
    compareTests(a, b);
    intArithmeticTests(a, b, true);
    assert(Fixed::min(a, b) == b);
    assert(Fixed::max(a, b) == a);
    const Fixed constA2 = a;
    const Fixed constB2 = b;
    assert(Fixed::min(constA2, constB2) == constB2);
    assert(Fixed::max(constA2, constB2) == constA2);
    std::cout << "testPlusIntegers completed." << std::endl;
}

void testMinusIntegers(Fixed a, Fixed b) {
    a = Fixed(-10);
    b = Fixed(-3);
    compareTests(b, a);
    intArithmeticTests(b, a, false);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == b);
    const Fixed constA = a;
    const Fixed constB = b;
    assert(Fixed::min(constA, constB) == constA);
    assert(Fixed::max(constA, constB) == constB);
    b = Fixed(-10);
    compareToEqualTests(a, b);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == a);
    const Fixed constA1 = a;
    const Fixed constB1 = b;
    assert(Fixed::min(constA1, constB1) == constA1);
    assert(Fixed::max(constA1, constB1) == constA1);
    a = Fixed(-10);
    b = Fixed(0);
    compareTests(b, a);
    intArithmeticTests(b, a, true);
    b = Fixed(-10);
    compareToEqualTests(a, b);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == b);
    const Fixed constA2 = a;
    const Fixed constB2 = b;
    assert(Fixed::min(constA2, constB2) == constA2);
    assert(Fixed::max(constA2, constB2) == constB2);
    std::cout << "testMinusIntegers completed." << std::endl;
}

void testPlusAndMinusIntegers(Fixed a, Fixed b) {
    a = Fixed(10);
    b = Fixed(-3);
    compareTests(a, b);
    intArithmeticTests(a, b, false);
    assert(Fixed::min(b, a) == b);
    assert(Fixed::max(b, a) == a);
    const Fixed constA = a;
    const Fixed constB = b;
    assert(Fixed::min(constA, constB) == constB);
    assert(Fixed::max(constA, constB) == constA);
    a = Fixed(-10);
    b = Fixed(3);
    compareTests(b, a);
    intArithmeticTests(b, a, false);
    assert(Fixed::min(b, a) == a);
    assert(Fixed::max(b, a) == b);
    const Fixed constA1 = a;
    const Fixed constB1 = b;
    assert(Fixed::min(constA1, constB1) == constA1);
    assert(Fixed::max(constA1, constB1) == constB1);
    std::cout << "testPlusAndMinusIntegers completed." << std::endl;
}

void testPlusFloats(Fixed a, Fixed b) {
    a = Fixed(10.5f);
    b = Fixed(3.2f);
    compareTests(a, b);
    floatArithmeticTests(a, b, false);
    assert(Fixed::min(a, b) == b);
    assert(Fixed::max(a, b) == a);
    const Fixed constA = a;
    const Fixed constB = b;
    assert(Fixed::min(constA, constB) == constB);
    assert(Fixed::max(constA, constB) == constA);
    b = Fixed(10.5f);
    compareToEqualTests(a, b);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == a);
    const Fixed constA1 = a;
    const Fixed constB1 = b;
    assert(Fixed::min(constA1, constB1) == constA1);
    assert(Fixed::max(constA1, constB1) == constA1);
    a = Fixed(10.5f);
    b = Fixed(0.0f);
    compareTests(a, b);
    floatArithmeticTests(a, b, true);
    assert(Fixed::min(a, b) == b);
    assert(Fixed::max(a, b) == a);
    const Fixed constA2 = a;
    const Fixed constB2 = b;
    assert(Fixed::min(constA2, constB2) == constB2);
    assert(Fixed::max(constA2, constB2) == constA2);
    std::cout << "testPlusFloats completed." << std::endl;
}

void testMinusFloats(Fixed a, Fixed b) {
    a = Fixed(-10.5f);
    b = Fixed(-3.2f);
    compareTests(b, a);
    floatArithmeticTests(b, a, false);
    assert(Fixed::min(b, a) == a);
    assert(Fixed::max(b, a) == b);
    const Fixed constA = a;
    const Fixed constB = b;
    assert(Fixed::min(constA, constB) == constA);
    assert(Fixed::max(constA, constB) == constB);
    b = Fixed(-10.5f);
    compareToEqualTests(a, b);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == a);
    const Fixed constA1 = a;
    const Fixed constB1 = b;
    assert(Fixed::min(constA1, constB1) == constA1);
    assert(Fixed::max(constA1, constB1) == constA1);
    a = Fixed(-10.5f);
    b = Fixed(0.0f);
    compareTests(b, a);
    floatArithmeticTests(b, a, true);
    assert(Fixed::min(b, a) == a);
    assert(Fixed::max(b, a) == b);
    const Fixed constA2 = a;
    const Fixed constB2 = b;
    assert(Fixed::min(constA2, constB2) == constA2);
    assert(Fixed::max(constA2, constB2) == constB2);
    std::cout << "testMinusFloats completed." << std::endl;
}

void testPlusAndMinusFloats(Fixed a, Fixed b) {
    a = Fixed(10.5f);
    b = Fixed(-3.2f);
    compareTests(a, b);
    floatArithmeticTests(a, b, false);
    assert(Fixed::min(a, b) == b);
    assert(Fixed::max(a, b) == a);
    const Fixed constA = a;
    const Fixed constB = b;
    assert(Fixed::min(constA, constB) == constB);
    assert(Fixed::max(constA, constB) == constA);
    a = Fixed(-10.5f);
    b = Fixed(3.2f);
    compareTests(b, a);
    floatArithmeticTests(b, a, false);
    assert(Fixed::min(a, b) == a);
    assert(Fixed::max(a, b) == b);
    const Fixed constA1 = a;
    const Fixed constB1 = b;
    assert(Fixed::min(constA1, constB1) == constA1);
    assert(Fixed::max(constA1, constB1) == constB1);
    std::cout << "testPlusAndMinusFloats completed." << std::endl;
}

int main(void) {
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
    }
    std::cout << "----------------" << std::endl;
    {
        Fixed a;
        Fixed b;

        testPlusIntegers(a, b);
        testMinusIntegers(a, b);
        testPlusAndMinusIntegers(a, b);

        testPlusFloats(a, b);
        testMinusFloats(a, b);
        testPlusAndMinusFloats(a, b);

        Fixed delta;
        delta++;
        std::cout << "Delta for increment/decrement tests: " << delta
                  << std::endl;
        a = Fixed(10);
        incrementDecrementTests(a, delta);
        a = Fixed(-10);
        incrementDecrementTests(a, delta);
        a = Fixed(10.5f);
        incrementDecrementTests(a, delta);
        a = Fixed(-10.5f);
        incrementDecrementTests(a, delta);
        a = Fixed(0);
        incrementDecrementTests(a, delta);
    }
    return 0;
}