#ifndef CIRCLETYPE_H_INCLUDED
#define CIRCLETYPE_H_INCLUDED

#include<iostream>

class circleType
{
public:
    void setRadius(double r);
    //Function to set the radius of the circle.
    //Postcondition: if(r >= 0) radius = r;
    //               otherwise radius = 0.0;

    double getRadius() const;
    //Function to return the radius of the circle.
    //Postcondition: The value of radius is returned.

    double area() const;
    //Function to return the area of the circle.
    //Postcondition: Area is calculated and returned.

    double circumference() const;
    //Function to return the circumference of the circle/
    //Postcondition: The value of circumference is calculated and returned.

    circleType();

    circleType(double r);
    //Constructor with a default parameter.
    //Radius is set according to the parameter.
    //The default value of the radius is 0.
    //Postcondition: radius = r;

private:
    double radius;
};

#endif // CIRCLETYPE_H_INCLUDED
