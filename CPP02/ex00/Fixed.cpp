#include "Fixed.hpp"
#include <iostream>

// Default constructor - initializes fixed-point number value to 0
Fixed::Fixed(void) : value(0) {
    std::cout << "Default constructor called" << std::endl;
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

// Returns the raw value of the fixed-point value
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

// Sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}
