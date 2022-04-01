#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Shape {
private:
    double perimeter, area;
public:
    double setPerimeter(double p) {
        if(p >= 0.0) perimeter = p;
        else perimeter = 0.0;
    }
    double getPerimeter() const {return perimeter;}
    double setArea(double a){
        if(a >= 0.0) area = a;
        else area = 0.0;
    }
    double getArea() const {return area;}
    Shape(){perimeter = 0.0; area = 0.0;}
};

class RightTriangle : public Shape {
private:
    double width, height;
public:
    void setData(double w, double h){
        if(w>=0.0) width = w;
        else width = 0;
        if(h>=0.0) height = h;
        else height = 0.0;
    }
    void calPerimeter(){
        double p, length;
        length = sqrt(width*width+height*height);
        p = (length+width+height);
        Shape::setPerimeter(p);
    }
    void calArea(){
        double a;
        a = width*height/2;
        Shape::setArea(a);
    }
    RightTriangle() {width = 0.0; height = 0.0;}
    RightTriangle(double w, double h){
        setData(w, h);
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    void setData(double w, double h){
        if(w>=0.0) width = w;
        else width = 0.0;
        if(h>=0.0) height = h;
        else height = 0.0;
    }
    void calPerimeter(){
        double p;
        p = 2*(width+height);
        Shape::setPerimeter(p);
    }
    void calArea(){
        double a;
        a = width*height;
        Shape::setArea(a);
    }
    Rectangle() {width = 0.0, height = 0.0;}
    Rectangle(double w, double h){
        setData(w, h);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    void setData(double r){
        if(r>=0.0) radius = r;
        else radius = 0.0;
    }
    void calPerimeter(){
        double p;
        p = 2*3.14159265*radius;
        Shape::setPerimeter(p);
    }
    void calArea(){
        double a;
        a = 3.14159265*(radius*radius);
        Shape::setArea(a);
    }
    Circle() {radius = 0.0;}
    Circle(double r){
        setData(r);
    }
};

void setOutputFormat(ostream &os) {
    cout << fixed << showpoint << setprecision(4);
}


int main() {

	setOutputFormat(cout);

	string type;

	int count = 0;

	double input1, input2;

	RightTriangle *t0;
	Rectangle *r0;
	Circle *c0;

	for(int count = 0; cin >> type >> input1; ++count) {

		switch(type[0]) {
			case 'T':
				cin >> input2;
				if(count % 2) {
					t0 = new RightTriangle(input1, input2);
				} else {
					t0 = new RightTriangle();
					t0->setData(input1, input2);
				}
				t0->calPerimeter();
				t0->calArea();
				cout << t0->getPerimeter() << " " << t0->getArea() << endl;
				break;
			case 'R':
				cin >> input2;
				if(count % 2) {
					r0 = new Rectangle(input1, input2);
				} else {
					r0 = new Rectangle();
					r0->setData(input1, input2);
				}
				r0->calPerimeter();
				r0->calArea();
				cout << r0->getPerimeter() << " " << r0->getArea() << endl;
				break;
			case 'C':
				if(count % 2) {
					c0 = new Circle(input1);
				} else {
					c0 = new Circle();
					c0->setData(input1);
				}
				c0->calPerimeter();
				c0->calArea();
				cout << c0->getPerimeter() << " " << c0->getArea() << endl;
				break;
		}
	}

	return 0;
}

