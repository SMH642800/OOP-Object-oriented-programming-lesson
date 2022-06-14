// Exmaple 13-0-2: complex numbers

#include <iostream>

using namespace std;

class complexType
{
      friend ostream& operator<<(ostream&, const complexType&);
      friend istream& operator>>(istream&, complexType&);

   public:
      void setComplex(const double &real, const double &imag)
      {
         realPart = real;
         imaginaryPart = imag;
      }
      void getComplex(double &real, double &imag) const
      {
         real = realPart;
         imag = imaginaryPart;
      }
      complexType(double real = 0, double imag = 0)
      {
         setComplex(real, imag);
      }

      complexType operator+(const complexType& otherComplex) const
      {
         complexType tempComplex;

         tempComplex.realPart = realPart + otherComplex.realPart;
         tempComplex.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

         return tempComplex;
      }
      complexType operator*(const complexType& otherComplex) const
      {
         complexType tempComplex;

         tempComplex.realPart = (realPart * otherComplex.realPart) - (imaginaryPart * otherComplex.imaginaryPart);
         tempComplex.imaginaryPart = (realPart * otherComplex.imaginaryPart) + (imaginaryPart * otherComplex.realPart);

         return tempComplex;
      }
      bool operator==(const complexType& otherComplex) const
      {
         return (realPart == otherComplex.realPart && imaginaryPart == otherComplex.imaginaryPart);
      }

   private:
      double realPart, imaginaryPart;
};

ostream& operator<<(ostream& osObject, const complexType& complex)
{
   osObject << "(";
   osObject << complex.realPart;
   osObject << ", ";
   osObject << complex.imaginaryPart;
   osObject << ")";

   return osObject;
}

istream& operator>>(istream& is, complexType& complex)
{
   char ch;

   is >> ch;
   is >> complex.realPart;
   is >> ch;
   is >> complex.imaginaryPart;
   is >> ch;
   
   return is;
}

int main()
{
   complexType num1(21, 18);
   complexType num2;
   complexType num3;

   cout << "Num1 = " << num1 << endl;
   cout << "Num2 = " << num2 << endl;

   cout << "Enter a complex number in the form (a, b): ";
   cin >> num2;
   cout << endl;

   cout << "New value of num2 = " << num2 << endl;

   num3 = num1 + num2;
   cout << "Num3 = " << num3 << endl;
   cout << "Num1 + Num2 = " << num1 + num2 << endl;
   cout << "Num1 * Num2 = " << num1 * num2 << endl;

   return 0;
}