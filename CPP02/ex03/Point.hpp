#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x; // x coordinate
    const Fixed y; // y coordinate

public:
    // Orthodox Canonical Form
    Point(void);                    // Default constructor
    Point(const Point& src);        // Copy constructor
    Point(const float x, const float y); // Constructor with coordinates
    ~Point(void);                   // Destructor

    // Copy assignment operator (private because x and y are const)
    Point& operator=(const Point& rhs);

    // Getters
    Fixed getX(void) const;
    Fixed getY(void) const;
};

// Function to check if point is inside triangle
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
