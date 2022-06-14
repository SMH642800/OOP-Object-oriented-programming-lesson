// Exmaple 13-5: overloading binary operators

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

      rectangleType operator+(const rectangleType& rectangle) const
      {
         rectangleType tempRect;
         tempRect.length = length + rectangle.length;
         tempRect.width = width + rectangle.width;

         return tempRect;
      }
      rectangleType operator*(const rectangleType& rectangle) const
      {
         rectangleType tempRect;
         tempRect.length = length * rectangle.length;
         tempRect.width = width * rectangle.width;

         return tempRect;
      }
      bool operator==(const rectangleType& rectangle) const
      {
         return (length == rectangle.length && width == rectangle.width);
      }
      bool operator!=(const rectangleType& rectangle) const
      {
         return !(length == rectangle.length && width == rectangle.width);
      }

   private:
      double length, width;
};

int main()
{
   rectangleType rectangle1(23, 45);
   rectangleType rectangle2(12, 10);
   rectangleType rectangle3;
   rectangleType rectangle4;

   // cout << fixed << showpoint << setprecision(2);

   cout << "rectangleType1: ";
   rectangle1.print();
   cout << endl;

   cout << "rectangleType2: ";
   rectangle2.print();
   cout << endl;

   rectangle3 = rectangle1 + rectangle2;
   cout << "rectangleType3: ";
   rectangle3.print();
   cout << endl;  

   rectangle4 = rectangle1 * rectangle2;
   cout << "rectangleType4: ";
   rectangle4.print();
   cout << endl;  

   if (rectangle1 == rectangle2) cout << "rectangle1 and rectangle2 are equal" << endl;
   else cout << "rectangle1 and rectangle2 are not equal" << endl;

   if (rectangle1 != rectangle3) cout << "rectangle1 and rectangle3 are not equal" << endl;
   else cout << "rectangle1 and rectangle3 are equal" << endl;

   return 0;
}
