#include "Shapemodifier.h"

Polygon operator+(const Polygon& lhs, const Polygon& rhs)
{
    Polygon newPolygon;
    newPolygon.sizeOfArray = rhs.sizeOfArray + lhs.sizeOfArray;
    Coordinates * newArray = new Coordinates[newPolygon.sizeOfArray];

    for(int i = 0; i < lhs.sizeOfArray; i++)
    {
        newArray[i] = lhs.arrayPoly[i];
    }
    for(int i = lhs.sizeOfArray; i < newPolygon.sizeOfArray; i++)
    {
        newArray[i] = rhs.arrayPoly[i-lhs.sizeOfArray];
    }

    // point poly to newly created array.
    newPolygon.arrayPoly = newArray;

    return newPolygon;
}

/*       
*       no need because im only loading polygons from the file,
*       im aware that polygon is a bad name since the file may give me points or lines
*       may give me points or lines but it is how it is
*
Polygon operator+(const Polygon& lhs, const Triangle& rhs)
{
    Coordinates * newArray = new Coordinates[3];

    newArray[0] = rhs.getCoordinateT1();
    newArray[1] = rhs.getCoordinateT2();
    newArray[2] = rhs.getCoordinateT3();

    Polygon triangle(newArray, 3);

    return lhs + triangle;
}

Polygon operator+(const Triangle& lhs, const Polygon& rhs)
{
    Coordinates * newArray = new Coordinates[3];

    newArray[0] = lhs.getCoordinateT1();
    newArray[1] = lhs.getCoordinateT2();
    newArray[2] = lhs.getCoordinateT3();

    Polygon triangle(newArray, 3);

    return triangle + rhs;
}


Polygon operator+(const Polygon& lhs, const Line& rhs)
{
    Coordinates * newArray = new Coordinates[2];

    newArray[0] = rhs.getCoordinateL1();
    newArray[1] = rhs.getCoordinateL2();

    Polygon line(newArray, 2);

    return lhs + line;
}

Polygon operator+(const Line& lhs, const Polygon& rhs)
{
    Coordinates * newArray = new Coordinates[2];

    newArray[0] = lhs.getCoordinateL1();
    newArray[1] = lhs.getCoordinateL2();

    Polygon line(newArray, 2);

    return line + rhs;
}

Polygon operator+(const Polygon& lhs, const Point& rhs)
{
    Coordinates * newArray = new Coordinates[1];

    newArray[0] = rhs.getCoordinate();

    Polygon point(newArray, 1);

    return lhs + point;
}

Polygon operator+(const Point& lhs, const Polygon& rhs)
{
    Coordinates * newArray = new Coordinates[1];

    newArray[0] = lhs.getCoordinate();

    Polygon point(newArray, 1);

    return lhs + point;
}

Polygon operator+(const Triangle& lhs, const Triangle& rhs)
{
    Coordinates * newArray = new Coordinates[3];

    newArray[0] = rhs.getCoordinateT1();
    newArray[1] = rhs.getCoordinateT2();
    newArray[2] = rhs.getCoordinateT3();

    Polygon triangle(newArray, 3);
    
    return lhs + triangle;
}

Polygon operator+(const Triangle& lhs, const Line& rhs)
{
    Coordinates * newArray = new Coordinates[2];

    newArray[0] = rhs.getCoordinateL1();
    newArray[1] = rhs.getCoordinateL2();

    Polygon line(newArray, 2);

    return lhs + line;
}
Polygon operator+(const Line& lhs, const Triangle& rhs)
{
    Coordinates * newArray = new Coordinates[2];

    newArray[0] = lhs.getCoordinateL1();
    newArray[1] = lhs.getCoordinateL2();

    Polygon line(newArray, 2);

    return line + rhs;
}

Polygon operator+(const Line& lhs, const Line& rhs)
{
    Coordinates * newArray = new Coordinates[2];

    newArray[0] = lhs.getCoordinateL1();
    newArray[1] = lhs.getCoordinateL2();

    Polygon line(newArray, 2);

    return line + rhs;
}

Triangle operator+(const Line& lhs, const Point& rhs)
{
    return Triangle(lhs.getCoordinateL1(), lhs.getCoordinateL2(), rhs.getCoordinate());
}
Triangle operator+(const Point& lhs, const Line& rhs)
{
    return Triangle(lhs.getCoordinate(), rhs.getCoordinateL1(), rhs.getCoordinateL2());
}

Line operator+(const Point& lhs, const Point& rhs)
{
    return Line(lhs.getCoordinate(), rhs.getCoordinate());
}
*/