#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(Coordinates coordinatesT1, Coordinates coordinatesT2, Coordinates coordinatesT3);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;
    
    Coordinates getCoordinateT1() const;
    Coordinates getCoordinateT2() const;
    Coordinates getCoordinateT3() const;
private:
    Coordinates coordinatesT1;
    Coordinates coordinatesT2;
    Coordinates coordinatesT3; 
};

#endif