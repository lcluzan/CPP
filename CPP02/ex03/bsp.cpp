#include "Point.hpp"

// Calculate the area of a triangle using the cross product method
static Fixed area(Point const a, Point const b, Point const c) {
    Fixed area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
                 (c.getX() - a.getX()) * (b.getY() - a.getY())) / 2;
    return area.toFloat() < 0 ? area * -1 : area;
}

// Check if point P is inside triangle ABC using barycentric coordinates
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate areas of the full triangle and three sub-triangles
    Fixed areaABC = area(a, b, c);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPAC = area(point, a, c);
    Fixed areaPAB = area(point, a, b);

    // If any sub-area is 0, the point lies on an edge or vertex (not inside)
    if (areaPBC.toFloat() == 0 || areaPAC.toFloat() == 0 || areaPAB.toFloat() == 0) {
        return false;
    }

    // Calculate barycentric coordinates
    Fixed alpha = areaPBC / areaABC;
    Fixed beta = areaPAC / areaABC;
    Fixed gamma = areaPAB / areaABC;

    // Point is inside if all barycentric coordinates are positive and sum to 1
    return (alpha.toFloat() > 0 && beta.toFloat() > 0 && gamma.toFloat() > 0 &&
            (alpha + beta + gamma).toFloat() == 1.0f);
}
