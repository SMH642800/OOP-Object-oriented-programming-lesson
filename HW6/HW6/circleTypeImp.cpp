#include "circleType.h"
#include "negativeNumber.h"
#include <iostream>

using namespace std;

void circleType::setRadius(double r)
{
    if (r < 0)
        throw negativeNumber("Radius");
    radius = r;
}

double circleType::getRadius() const {return radius;}
double circleType::area() const {return 3.1416*radius*radius;}
double circleType::circumference() const {return 2*3.1416*radius;}

circleType::circleType(){radius = 0;}

circleType::circleType(double r)
{
    setRadius(r);
}
