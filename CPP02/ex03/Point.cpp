#include "Point.hpp"

// Default constructor - initializes point to (0,0)
Point::Point(void) : x(0), y(0) {
}

// Copy constructor
Point::Point(const Point& src) : x(src.x), y(src.y) {
}

// Constructor with coordinates
Point::Point(const float x, const float y) : x(x), y(y) {
}

// Destructor
Point::~Point(void) {
}

// Copy assignment operator (unused because x and y are const)
Point& Point::operator=(const Point& rhs) {
    (void)rhs; // Avoid unused parameter warning
    return *this;
}

// Getters
Fixed Point::getX(void) const {
    return this->x;
}

Fixed Point::getY(void) const {
    return this->y;
}
