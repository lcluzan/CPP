#ifndef FIXED_HPP
#define FIXED_HPP

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

    // Member functions
    int getRawBits(void) const;    // Returns the raw value
    void setRawBits(int const raw); // Sets the raw value
};

#endif
