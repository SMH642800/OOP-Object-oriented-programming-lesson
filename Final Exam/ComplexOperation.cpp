#include <iostream>

using namespace std;

class Complex
{
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);

private:
	int real, image;

public:
	Complex()
	{
        real = 0;
        image = 0;
	}
	Complex(int r, int i) : real(r), image(i)
	{
        real = r;
        image = i;
	}

	Complex operator+(const Complex& otherComplex) const
	{
	    Complex tempComplex;
	    tempComplex.real = real + otherComplex.real;
	    tempComplex.image = image + otherComplex.image;
	    return tempComplex;
	}
	Complex operator-(const Complex& otherComplex) const
	{
	    Complex tempComplex;
	    tempComplex.real = real - otherComplex.real;
	    tempComplex.image = image - otherComplex.image;
	    return tempComplex;
	}
	Complex operator*(const Complex& otherComplex) const
	{
	    Complex tempComplex;
	    tempComplex.real = (real*otherComplex.real) - (image*otherComplex.image);
	    tempComplex.image = (real*otherComplex.image) + (image*otherComplex.real);
	    return tempComplex;
	}
	Complex operator/(const Complex& otherComplex) const
	{
	    Complex tempComplex;
	    int a, b, c, d;
	    a = real;
	    b = image;
	    c = otherComplex.real;
	    d = otherComplex.image;
	    tempComplex.real = (a*c + b*d) / (c*c + d*d);
	    tempComplex.image = (b*c - a*d) / (c*c + d*d);
	    return tempComplex;
	}
};

ostream& operator<<(ostream& osObject, const Complex& complexObject)
{
   osObject << complexObject.real;
   if(complexObject.image < 0)
        osObject << complexObject.image;
   else{
        osObject << "+";
        osObject << complexObject.image;
   }
   osObject << "i";

   return osObject;
}

istream& operator>>(istream& isObject, Complex& complexObject)
{
   char ch;

   //isObject >> ch;
   isObject >> complexObject.real;
   //isObject >> ch;
   isObject >> complexObject.image;
   //isObject >> ch;

   return isObject;
}

int main() {

	Complex c1, c2;
	char op;
	while(cin >> c1 >> op >> c2) {
		switch(op) {
			case '+':
				cout << c1 + c2 << endl;
				break;
			case '-':
				cout << c1 - c2 << endl;
				break;
			case '*':
				cout << c1 * c2 << endl;
				break;
			case '/':
				cout << c1 / c2 << endl;
				break;
		}
	}
}
