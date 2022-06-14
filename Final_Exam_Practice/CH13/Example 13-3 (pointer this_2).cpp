// Exmaple 13-3: pointer this

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

      rectangleType& setLength(double l)
      {
         length = l;
         return *this;
      }
      rectangleType& setWidth(double w)
      {
         width = w;
         return *this;
      }
   
   private:
      double length, width;
};

int main()
{
   rectangleType myRectangle;
   rectangleType yourRectangle;

   cout << fixed << showpoint << setprecision(2);

   myRectangle.setLength(15.25).setWidth(12.00);
   
   cout << "myRectangle: ";
   myRectangle.print();
   cout << endl;

   yourRectangle.setLength(18.50);
   cout << "After setting yourRectangle length, yourRectangle: ";
   yourRectangle.print();
   cout << endl;

   yourRectangle.setWidth(7.50);
   cout << "After setting yourRectangle width, yourRectangle: ";
   yourRectangle.print();
   cout << endl;

   return 0;
}
