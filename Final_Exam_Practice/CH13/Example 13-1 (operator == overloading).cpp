// Exmaple 13-1: clock equal(==) operator overloading mehtod

#include <iostream>

using namespace std;

class clockType
{
   public:
      void setTime(int hours, int minutes, int seconds)
      {
         if (0 <= hours && hours < 24) hr = hours;
         else hr = 0;

         if (0 <= minutes && minutes < 60) min = minutes;
         else min = 0;

         if (0 <= seconds && seconds < 60) sec = seconds;
         else sec = 0;
      }
      void printTime() const
      {
         if (hr < 10) cout << "0";
         cout << hr << ":";

         if (min < 10) cout << "0";
         cout << min << ":";

         if (sec < 10) cout << "0";
         cout << sec;
      }

      bool operator==(const clockType& otherClock) const
      { 
         return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
      }

      clockType(int h = 0, int m = 0, int s = 0)
      {
         setTime(h, m, s);
      }
   
   private:
      int hr, min, sec;
};

int main()
{
   clockType myClock(8, 23, 50);
   clockType yourClock(8, 23, 50);
   clockType tempClock(9, 16, 25);

   cout << "myClock: ";
   myClock.printTime();
   cout << endl;

   cout << "myClock: ";
   yourClock.printTime();
   cout << endl;

   cout << "myClock: ";
   tempClock.printTime();
   cout << endl;

   if (myClock == yourClock)
      cout << "The time of myClock is equal to yourClock." << endl;
   else
      cout << "The time of myClock is not equal to yourClock." << endl;
   
   if (myClock == tempClock)
      cout << "The time of myClock is equal to tempClock." << endl;
   else
      cout << "The time of myClock is not equal to tempClock." << endl;

   return 0;
}
