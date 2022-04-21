#include <iostream>
#include <iomanip>

using namespace std;

class Shape {
public:
    double bottom, height, area;
    virtual void calArea() = 0;
    double getArea() const {return area;}
};

class Parallelogram : public Shape {
public:
    void calArea() {area = bottom*height;}
    Parallelogram(double b, double h)
    {
        if(b < 0) bottom = 0;
        else bottom = b;

        if(h < 0) height = 0;
        else height = h;
    }
};

class Trapezoid : public Shape {
private:
    double top;
public:
    void calArea() {area = (top + bottom)*height / 2;}
    Trapezoid() {}
    Trapezoid(double t, double b, double h)
    {
        if(t < 0) top = 0;
        else top = t;

        if(b < 0) bottom = 0;
        else bottom = b;

        if(h < 0) height = 0;
        else height = h;
    }
};

class Triangle : public Trapezoid {
public:
    void calArea() {area = bottom*height / 2;}
    Triangle(double b, double h)
    {
        if(b < 0) bottom = 0;
        else bottom = b;

        if(h < 0) height = 0;
        else height = h;
    }
};

void setOutputFormat(ostream &os) {
    cout << fixed << showpoint << setprecision(2);
}

int main() {

	setOutputFormat(cout);

	Parallelogram *para;
	Trapezoid *trap;
	Triangle *tria;

	string s;

	double n[3];

	while(cin >> s) {

		switch(s[0]) {
			case 'P':
				cin >> n[0] >> n[1];
				para = new Parallelogram(n[0], n[1]);
				para->calArea();
				cout << para->getArea() << endl;
				delete para;
				break;
			case 'T':
				cin >> n[0] >> n[1] >> n[2];
				trap = new Trapezoid(n[0], n[1], n[2]);
				trap->calArea();
				cout << trap->getArea() << endl;
				delete trap;
				break;
			case '3':
				cin >> n[0] >> n[1];
				tria = new Triangle(n[0], n[1]);
				tria->calArea();
				cout << tria->getArea() << endl;
				delete tria;
				break;
		}
	}
}
