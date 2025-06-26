#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "Testing increment/decrement operators:" << std::endl;
    std::cout << "a   : " << a << std::endl;
    std::cout << "++a : " << ++a << std::endl;
    std::cout << "a   : " << a << std::endl;
    std::cout << "a++ : " << a++ << std::endl;
    std::cout << "a   : " << a << std::endl;
    std::cout << std::endl;

    std::cout << "Testing arithmetic and comparison:" << std::endl;
    std::cout << "b   : " << b << std::endl;
    std::cout << "max(a,b): " << Fixed::max(a, b) << std::endl;
    std::cout << "min(a,b): " << Fixed::min(a, b) << std::endl;
    std::cout << std::endl;

    Fixed c(3.14f);
    Fixed d(2.0f);

    std::cout << "Testing more arithmetic operations:" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "c + d = " << c + d << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "c * d = " << c * d << std::endl;
    std::cout << "c / d = " << c / d << std::endl;
    std::cout << std::endl;

    std::cout << "Testing comparison operators:" << std::endl;
    std::cout << "c > d  : " << (c > d) << std::endl;
    std::cout << "c < d  : " << (c < d) << std::endl;
    std::cout << "c >= d : " << (c >= d) << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;

    return 0;
}
