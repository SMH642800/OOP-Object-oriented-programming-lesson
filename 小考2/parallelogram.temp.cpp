#include <iostream>
#include <iomanip>

using namespace std;

class Parallelogram {
protected:
    double bottomSide, height, area;
    void calArea() {area = bottomSide*height;}
public:
    void setData(double b, double h){
        if(b >= 0.0) bottomSide = b;
        else bottomSide = 0.0;
        if(h >= 0.0) height = h;
        else height = 0.0;
    }
    double getArea() const {return area;}
    Parallelogram() {bottomSide = 0.0; height = 0.0; area = 0.0;}
    Parallelogram(double b, double h){
        setData(b, h);
        calArea();
    }
};

class Trapezoid : public Parallelogram
{
private:
    double topSide;
protected:
    void calArea(){
        area = (topSide+bottomSide)*height/2;
    }
public:
    double getArea() const {return area;}
    Trapezoid(double t = 0.0, double b = 0.0, double h = 0.0){
        if(t >= 0.0) topSide = t;
        else topSide = 0.0;
        Parallelogram::setData(b, h);
        calArea();
    }
};

void setFormat(ostream &os) {
    cout << fixed << showpoint << setprecision(2);
}

int main() {

	setFormat(cout);

	string type;

	double ts, bs, h;

	Parallelogram *p;
	Trapezoid *t;

	while(cin >> type) {

		switch(type[0]) {

			case 'P':
				cin >> bs >> h;
				p = new Parallelogram(bs, h);
				cout << "P " << p->getArea() << endl;
				break;
			case 'T':
				cin >> ts >> bs >> h;
				t = new Trapezoid(ts, bs, h);
				cout << "T " << t->getArea() << endl;
				break;
		}
	}

}
