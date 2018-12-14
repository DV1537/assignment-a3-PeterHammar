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

Shape& defineShape(Coordinates *array, int sizeOfArray);
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

    Coordinates *arrayShape1 = new Coordinates[sizeOfArray1];
    Coordinates *arrayShape2 = new Coordinates[sizeOfArray2];

    for (int i = 0; i < sizeOfArray1; i += 2)
    {
        arrayShape1[i / 2].x = array1[i];
        arrayShape1[i / 2].y = array1[i + 1];
    }

    Shape &shape1 = defineShape(arrayShape1, sizeOfArray1);

    for (int i = 0; i < sizeOfArray2; i += 2)
    {
        arrayShape2[i / 2].x = array2[i];
        arrayShape2[i / 2].y = array2[i + 1];
    }

    Shape &shape2 = defineShape(arrayShape2, sizeOfArray2);

    cout << "area for shape is: \n";
    if (sizeOfArray1 == 2)
    {
        Point shape1 = Point(arrayShape1, sizeOfArray1/2);
        if (sizeOfArray2 == 2)
        {
            Point shape2 = Point(arrayShape2, sizeOfArray2/2);
            Line shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 4)
        {
            Line shape2 = Line(arrayShape2, sizeOfArray2/2);
            Triangle shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 6)
        {
            Triangle shape2 = Triangle(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 >= 8)
        {
            Polygon shape2 = Polygon(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
    }
    if (sizeOfArray1 == 4)
    {
        Line shape1 = Line(arrayShape1, sizeOfArray1/2);
        if (sizeOfArray2 == 2)
        {
            Point shape2 = Point(arrayShape2, sizeOfArray2/2);
            Triangle shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 4)
        {
            Line shape2 = Line(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 6)
        {
            Triangle shape2 = Triangle(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 >= 8)
        {
            Polygon shape2 = Polygon(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
    }
    if (sizeOfArray1 == 6)
    {
        Triangle shape1 = Triangle(arrayShape1, sizeOfArray1/2);
        if (sizeOfArray2 == 2)
        {
            Point shape2 = Point(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 4)
        {

            Line shape2 = Line(arrayShape2, sizeOfArray2/2);

            Polygon shape = shape1 + shape2;

            printArea(&shape);
        }
        if (sizeOfArray2 == 6)
        {
            Triangle shape2 = Triangle(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 >= 8)
        {
            Polygon shape2 = Polygon(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
    }
    if (sizeOfArray1 >= 8)
    {
        Polygon shape1 = Polygon(arrayShape1, sizeOfArray1/2);
        if (sizeOfArray2 == 2)
        {
            Point shape2 = Point(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 4)
        {
            Line shape2 = Line(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 == 6)
        {
            Triangle shape2 = Triangle(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
        if (sizeOfArray2 >= 8)
        {
            Polygon shape2 = Polygon(arrayShape2, sizeOfArray2/2);
            Polygon shape = shape1 + shape2;
            printArea(&shape);
        }
    }
    return 0;
}

Shape& defineShape(Coordinates *array, int sizeOfArray)
{
    Shape *newShape;
    if(sizeOfArray == 2)
    {
        newShape = new Point(array, sizeOfArray);
    }
    else if(sizeOfArray == 4)
    {
        newShape = new Line(array, sizeOfArray);
    }
    else if(sizeOfArray == 6)
    {
        newShape = new Triangle(array, sizeOfArray);
    }
    else if(sizeOfArray > 6)
    {
        newShape = new Polygon(array, sizeOfArray);
    }

    return *newShape;
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

    std::cout << " " << area << std::endl;
}

void printCircumference(Shape *shape)
{
    double circumference = shape->circumference();

    std::cout << "circumference is: " << circumference << std::endl;
}