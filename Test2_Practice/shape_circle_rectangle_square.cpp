#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class rectangleType
{
public:
    void setDimension(double l, double w){
        if(l >= 0) length = l;
        else length = 0;

        if(w >= 0) width = w;
        else width = 0;
    }

    double getLength() const {return length;}
    double getWidth() const {return width;}
    double area() const {return length*width;}
    double perimeter() const {return 2*(length + width);}

    void print() const {
        cout << "Length = " << length
             << ", Width = " << width;
    }

    rectangleType(double l = 0, double w = 0){
        setDimension(l, w);
    }

private:
    double length, width;
};

class boxType: rectangleType
{
public:
    void setDimension(double l, double w, double h){
        rectangleType::setDimension(l, w);
        if(h >= 0) height = h;
        else height = 0;
    }

    double getHeight() const {return height;}
    double area() const {return 2*(getLength()*getWidth() + getLength()*height + getWidth()*height);}
    double volume() const {return rectangleType::area() * height;}

    void print() const{
        rectangleType::print();
        cout << ", Height = " << height << endl;
    }

    boxType(double l = 0, double w = 0, double h = 0) : rectangleType(l, w) {
        if(h >= 0) height = h;
        else height = 0;
    }

private:
    double height;
};

int main()
{
    rectangleType yard;
    double fenceCostPerFoot, fertilizerCostPerSquareFoot;
    double length, width;
    double billingAmount;

    cout << fixed << setprecision(4);

    cout << "Enter the length and width of the yard (in feet): ";
    cin >> length >> width;
    cout << endl;

    yard.setDimension(length, width);

    cout << "Enter the cost of fence (per foot): $";
    cin >> fenceCostPerFoot;
    cout << endl;

    cout << "Enter the cost of fertilizer (per square of foot): $";
    cin >> fertilizerCostPerSquareFoot;
    cout << endl;

    billingAmount = yard.perimeter() * fenceCostPerFoot + yard.area() * fertilizerCostPerSquareFoot;
    cout << "Amount due: $" << billingAmount << endl;

    boxType package;
    double height;
    double wrappingCostPerSquareFeet;

    cout << "Enter the length, width, and height of the package (in feet): ";
    cin >> length >> width >> height;
    cout << endl;

    package.setDimension(length, width, height);

    cout << "Enter the cost (25 to 50 cents) of wrapping per square foot: ";
    cin >> wrappingCostPerSquareFeet;
    cout << endl;

    billingAmount = wrappingCostPerSquareFeet * package.area()/100;
    if(billingAmount < 1.00) billingAmount = 1.00;

    cout << "Amount due: $" << billingAmount << endl;

    yard.print();
    cout << endl;
    package.print();


    return 0;
}
