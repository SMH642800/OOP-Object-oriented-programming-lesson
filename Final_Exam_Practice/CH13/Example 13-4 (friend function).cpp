// Exmaple 13-4: friend function

#include <iostream>
#include <iomanip>

using namespace std;

class rectangleType
{
      friend void rectangleFriend(rectangleType recObject);

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

   private:
      double length, width;
};

void rectangleFriend(rectangleType recFriendObject)
{
   cout << "recFriendObject area: " << recFriendObject.area() << endl;

   recFriendObject.length = recFriendObject.length + 5;
   recFriendObject.width = recFriendObject.width + 5;

   cout << "After increasing length and width by 5 units each, recFriendObject area: " << recFriendObject.area();
}

int main()
{
   rectangleType myYard(25, 18);

   cout << fixed << showpoint << setprecision(2);

   cout << "myYard area: " << myYard.area() << endl;
   cout << "passing object myYard to the friend function rectangleFriend." << endl;

   rectangleFriend(myYard);

   return 0;
}
