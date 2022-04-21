#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Position
{
    double X, Y;
};

class Triangle
{
private:
    Position A, B, C;
public:
    void printGravity(ostream &os)
    {
        if(A.X == B.X && A.Y == B.Y) cout << (A.X + C.X)/2 << " " << (A.Y + C.Y)/2 << endl;
        else if(B.X == C.X && B.Y == C.Y) cout << (A.X + B.X)/2 << " " << (A.Y + B.Y)/2 << endl;
        else if(A.X == C.X && A.Y == C.Y) cout << (B.X + C.X)/2 << " " << (B.Y + C.Y)/2 << endl;
        else cout << (A.X + B.X + C.X)/3 << " " << (A.Y + B.Y + C.Y)/3 << endl;
    }
    void printArea(ostream &os)
    {
        double area = 0;
        double s = 0;
        double a1 = 0, b1 = 0, c1 = 0;
        a1 = sqrt((B.X-A.X)*(B.X-A.X) + (B.Y-A.Y)*(B.Y-A.Y));
        b1 = sqrt((C.X-B.X)*(C.X-B.X) + (C.Y-B.Y)*(C.Y-B.Y));
        c1 = sqrt((C.X-A.X)*(C.X-A.X) + (C.Y-A.Y)*(C.Y-A.Y));
        s = (a1 + b1 + c1) / 2;
        area = sqrt(s*(s-a1)*(s-b1)*(s-c1));
        cout << area << endl;
    }

    Triangle(Position a, Position b, Position c)
    {
        A.X = a.X;
        A.Y = a.Y;

        B.X = b.X;
        B.Y = b.Y;

        C.X = c.X;
        C.Y = c.Y;
    }
};

void setOutputFormat(ostream &os) {
    cout << fixed << setprecision(4);
}

int main() {

	setOutputFormat(cout);

	Triangle *t;
	Position a, b, c;
	double x, y;

	while(cin >> x >> y) {

		a.X = x;
		a.Y = y;

		cin >> b.X >> b.Y;
		cin >> c.X >> c.Y;

		t = new Triangle(a, b, c);

		t->printGravity(cout);
		t->printArea(cout);

		delete t;
	}
}
