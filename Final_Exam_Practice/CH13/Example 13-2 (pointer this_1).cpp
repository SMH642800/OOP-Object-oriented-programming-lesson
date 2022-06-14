// Exmaple 13-2: pointer this

#include <iostream>
#include <iomanip>

using namespace std;

class rectangleType
{
   public:
      void setDimension(int l, int w)
      {
         if(l >= 0) length = l;
         else length = 0;

         if(w >= 0) width = w;
         else width = 0;
      }

      double getLength() const {return length;}
      double getWidth() const {return width;}
      double area() const {return length*width;}
      double perimeter() const {return 2*(length + width);}

      void print() const 
      {
         cout << "Length: " << length << ", width: " << width << endl;
      }

      rectangleType(double l = 0, double w = 0)
      {
         setDimension(l, w);
      }

      rectangleType& doubleDimension()
      {
         length = 2*length;
         width = 2*width;

         return *this;
      }
   
   private:
      double length, width;
};

int main()
{
   rectangleType oldYard(20.00, 10.00);
   rectangleType newYard;

   cout << fixed << showpoint << setprecision(2);

   cout << "Area of oldYard: " << oldYard.area() << endl;
   newYard = oldYard.doubleDimension();
   cout << "Area of newYard: " << newYard.area() << endl;

   return 0;
}
