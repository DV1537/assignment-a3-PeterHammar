#ifndef SHAPEMODIFIER_H
#define SHAPEMODIFIER_H

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

// 

Polygon operator+(const Polygon& lhs, const Polygon& rhs);

/*
*     dont need for this version, but y'know (more info in ShapeModifier.cpp)
*
Polygon operator+(const Polygon& lhs, const Triangle& rhs);
Polygon operator+(const Triangle& lhs, const Polygon& rhs);

Polygon operator+(const Polygon& lhs, const Line& rhs);
Polygon operator+(const Line& lhs, const Polygon& rhs);

Polygon operator+(const Polygon& lhs, const Point& rhs);
Polygon operator+(const Point& lhs, const Polygon& rhs);

Polygon operator+(const Triangle& lhs, const Triangle& rhs);

Polygon operator+(const Triangle& lhs, const Line& rhs);
Polygon operator+(const Line& lhs, const Triangle& rhs);

Polygon operator+(const Line& lhs, const Line& rhs);

Triangle operator+(const Line& lhs, const Point& rhs);
Triangle operator+(const Point& lhs, const Line& rhs);

Line operator+(const Point& lhs, const Point& rhs);
*
*
*/

#endif