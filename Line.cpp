#include "Line.h"

std::string Line::getType()
{
    return "Line";
}

double Line::area()
{
    return -1;
}

double Line::circumference()
{
    return 0;
}

Coordinates Line::position() 
{

    Coordinates coordinates;

    coordinates.x = (coordinatesL1.x + coordinatesL2.x)/2;
    coordinates.y = (coordinatesL1.y + coordinatesL2.y)/2;
    return coordinates;
}

Line::Line(Coordinates cL1, Coordinates cL2)
{
    coordinatesL1 = cL1;
    coordinatesL2 = cL2;
}

bool Line::isConvex()
{
    return false;
}

double Line::distance(Shape *s)
{

}

Coordinates Line::getCoordinateL1() const
{ 
    return coordinatesL1;
}

Coordinates Line::getCoordinateL2() const
{ 
    return coordinatesL2;
}
