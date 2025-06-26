#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default constructor
Fixed::Fixed(void) : value(0) {
}

// Int constructor
Fixed::Fixed(const int n) {
    this->value = n << this->fractionalBits;
}

// Float constructor
Fixed::Fixed(const float n) {
    this->value = roundf(n * (1 << this->fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& src) {
    *this = src;
}

// Destructor
Fixed::~Fixed(void) {
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        this->value = rhs.getRawBits();
    }
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const {
    return this->value > rhs.value;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->value < rhs.value;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->value >= rhs.value;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->value <= rhs.value;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->value == rhs.value;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->value != rhs.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->value + rhs.value);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->value - rhs.value);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    long long temp = (long long)this->value * (long long)rhs.value;
    result.setRawBits((int)(temp >> fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs.value == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    Fixed result;
    long long temp = ((long long)this->value << fractionalBits) / rhs.value;
    result.setRawBits(temp);
    return result;
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Conversion methods
float Fixed::toFloat(void) const {
    return (float)this->value / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const {
    return this->value >> this->fractionalBits;
}

// Min/Max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Member functions
int Fixed::getRawBits(void) const {
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
