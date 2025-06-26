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

    // Conversion operators
    float toFloat(void) const;  // Converts fixed point to float
    int toInt(void) const;      // Converts fixed point to int

    // Member functions
    int getRawBits(void) const;    // Returns the raw value
    void setRawBits(int const raw); // Sets the raw value
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
