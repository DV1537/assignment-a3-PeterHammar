#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "ShapeModifier.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void printType(Shape *shape);
void printPosition(Shape *shape);
void printArea(Shape *shape);
void printCircumference(Shape *shape);

int main()
{
    float p;
    int sizeOfArray1 = 1;
    int sizeOfArray2 = 1;
    float *array1 = new float[sizeOfArray1];
    float *array2 = new float[sizeOfArray2];

    ifstream myReadFile;

    myReadFile.open("a2.txt");

    int count1 = 0;
    int count2 = 0;
    if (!myReadFile)
    {
        return EXIT_FAILURE;
    }
    else
    {
        std::string line1;
        std::string line2;
        std::getline(myReadFile, line1);
        std::getline(myReadFile, line2);
        
        //parse line1 to a shape
        std::stringstream ss1(line1);
        while (ss1 >> p)
        {
            if (sizeOfArray1 <= count1)
            {
                sizeOfArray1 += 1;
                float *oldArray1 = array1;
                array1 = new float[sizeOfArray1];
                for (int i = 0; i < count1; i++)
                {
                    array1[i] = oldArray1[i];
                }
                delete[] oldArray1;
            }
            array1[count1] = p;
            ++count1;
        }

        //parse line2 as soon as line1 parsed
        
        std::stringstream ss2(line2);
        while (ss2 >> p)
        {
            if (sizeOfArray2 <= count2)
            {
                sizeOfArray2 += 1;
                float *oldArray2 = array2;
                array2 = new float[sizeOfArray2];
                for (int i = 0; i < count2; i++)
                {
                    array2[i] = oldArray2[i];
                }
                delete[] oldArray2;
            }
            array2[count2] = p;
            ++count2;
        }
        

        if (count1 % 2 == 1 || count2 % 2 == 1)
        {
            cout << "File needs an even amount of numbers.\n";
            return EXIT_FAILURE;
        }
    }
    myReadFile.close();

    // Regardless of the amount, create two polygons out of the given coordinates, 
    // and create a third polygon out of the two previous ones
    Coordinates *arrayPoly1 = new Coordinates[sizeOfArray1];
    Coordinates *arrayPoly2 = new Coordinates[sizeOfArray2];

    for (int i = 0; i < sizeOfArray1; i += 2)
    {
        arrayPoly1[i / 2].x = array1[i];
        arrayPoly1[i / 2].y = array1[i + 1];
    }

    Polygon polygon1(arrayPoly1, sizeOfArray1/2);
      
    for (int i = 0; i < sizeOfArray2; i += 2)
    {
        arrayPoly2[i / 2].x = array2[i];
        arrayPoly2[i / 2].y = array2[i + 1];
    }

    Polygon polygon2(arrayPoly2, sizeOfArray2/2);

    Polygon polygon3;
    polygon3 = polygon1 + polygon2;

    printType(&polygon3);
    printPosition(&polygon3);
    printArea(&polygon3);
    printCircumference(&polygon3);

    return 0;
}

void printType(Shape *shape)
{
    std::cout << "Type is: " << shape->getType() << std::endl;
}
void printPosition(Shape *shape)
{
    Coordinates coordinates = shape->position();
    std::cout << "Center coordinates: (" << coordinates.x << ", " << coordinates.y << ")" << std::endl;
}

void printArea(Shape *shape)
{
    double area = shape->area();

    std::cout << "area is: " << area << std::endl;
}

void printCircumference(Shape *shape)
{
    double circumference = shape->circumference();

    std::cout << "circumference is: " << circumference << std::endl;
}