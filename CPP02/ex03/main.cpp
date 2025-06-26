#include <iostream>
#include "Point.hpp"

int main(void) {
    // Create a triangle with vertices at (0,0), (10,30), and (20,0)
    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);

    // Test points
    Point p1(10, 15);    // Should be inside
    Point p2(10, 0);     // Should be outside (on edge)
    Point p3(30, 15);    // Should be outside
    Point p4(10, 10);    // Should be inside
    Point p5(0, 0);      // Should be outside (on vertex)

    // Test each point
    std::cout << "Testing points with triangle vertices at (0,0), (10,30), (20,0):" << std::endl;
    std::cout << "Point (10,15) is " << (bsp(a, b, c, p1) ? "inside" : "outside") << std::endl;
    std::cout << "Point (10,0) is " << (bsp(a, b, c, p2) ? "inside" : "outside") << std::endl;
    std::cout << "Point (30,15) is " << (bsp(a, b, c, p3) ? "inside" : "outside") << std::endl;
    std::cout << "Point (10,10) is " << (bsp(a, b, c, p4) ? "inside" : "outside") << std::endl;
    std::cout << "Point (0,0) is " << (bsp(a, b, c, p5) ? "inside" : "outside") << std::endl;

    return 0;
}
