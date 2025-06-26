#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;                          // Fixed point value
    static const int fractionalBits = 8; // Number of fractional bits

public:
    // Orthodox Canonical Form requirements
    Fixed(void);                // Default constructor
    Fixed(const Fixed& src);    // Copy constructor
    ~Fixed(void);              // Destructor
    Fixed& operator=(const Fixed& rhs); // Copy assignment operator

    // Additional constructors for conversion
    Fixed(const int n);        // Constructor from int
    Fixed(const float n);      // Constructor from float

    // Comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // Increment/Decrement operators
    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    // Conversion methods
    float toFloat(void) const;
    int toInt(void) const;

    // Min/Max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
