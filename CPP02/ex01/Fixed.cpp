#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default constructor - initializes fixed-point number value to 0
Fixed::Fixed(void) : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor - converts int to fixed point
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->value = n << this->fractionalBits;
}

// Float constructor - converts float to fixed point
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(n * (1 << this->fractionalBits));
}

// Copy constructor - initializes object as a copy of src object
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->value = rhs.getRawBits();
    }
    return *this;
}

// Converts fixed point to float
float Fixed::toFloat(void) const {
    return (float)this->value / (1 << this->fractionalBits);
}

// Converts fixed point to int
int Fixed::toInt(void) const {
    return this->value >> this->fractionalBits;
}

// Returns the raw value of the fixed-point value
int Fixed::getRawBits(void) const {
    return this->value;
}

// Sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
