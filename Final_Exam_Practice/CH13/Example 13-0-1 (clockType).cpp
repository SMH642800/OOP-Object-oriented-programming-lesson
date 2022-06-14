// Exmaple 13-0-1: clockType

#include <iostream>

using namespace std;

class clockType
{
      friend ostream& operator<<(ostream&, const clockType&);
      friend istream& operator>>(istream&, clockType&);

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
      void getTime(int &hours, int &minutes, int &seconds) const
      {
         hours = hr;
         minutes = min;
         seconds = sec;
      }
      clockType(int hours=0, int minutes=0, int seconds=0)
      {
         setTime(hours, minutes, seconds);
      }

      clockType operator++()
      {
         sec++;
         if(sec > 59)
         {
            sec = 0;
            min++;

            if(min > 59)
            {
               min = 0;
               hr++;

               if(hr > 23) hr = 0;
            }
         }

         return *this;
      }
      bool operator==(const clockType& otherClock) const
      {
         return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
      }
      bool operator!=(const clockType& otherClock) const
      {
         return !(hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
      }
      bool operator<=(const clockType& otherClock) const
      {
         return ((hr < otherClock.hr) ||
                 (hr == otherClock.hr && min < otherClock.min) ||
                 (hr == otherClock.hr && min == otherClock.min && sec <= otherClock.sec));
      }
      bool operator<(const clockType& otherClock) const
      {
         return ((hr < otherClock.hr) ||
                 (hr == otherClock.hr && min < otherClock.min) ||
                 (hr == otherClock.hr && min == otherClock.min && sec < otherClock.sec));
      }
      bool operator>=(const clockType& otherClock) const
      {
         return ((hr > otherClock.hr) ||
                 (hr == otherClock.hr && min > otherClock.min) ||
                 (hr == otherClock.hr && min == otherClock.min && sec >= otherClock.sec));
      }
      bool operator>(const clockType& otherClock) const
      {
         return ((hr > otherClock.hr) ||
                 (hr == otherClock.hr && min > otherClock.min) ||
                 (hr == otherClock.hr && min == otherClock.min && sec > otherClock.sec));
      }

   private:
      int hr, min, sec;
};

ostream& operator<<(ostream& osObject, const clockType& timeOut)
{
   if (timeOut.hr < 10) osObject << '0';
   osObject << timeOut.hr << ':';

   if (timeOut.min < 10) osObject << '0';
   osObject << timeOut.min << ':';

   if (timeOut.sec < 10) osObject << '0';
   osObject << timeOut.sec;

   return osObject;
}

istream& operator>>(istream& is, clockType& timeIn)
{
   char ch;

   is >> timeIn.hr;
   if (timeIn.hr < 0 || timeIn.hr >= 24) timeIn.hr = 0;

   is.get(ch);
   
   is >> timeIn.min;
   if (timeIn.min < 0 || timeIn.min >= 60) timeIn.min = 0;
   
   is.get(ch);
   
   is >> timeIn.sec;
   if (timeIn.sec < 0 || timeIn.sec >= 60) timeIn.sec = 0;

   return is;
}

int main()
{
   clockType myClock(7, 24, 32);
   clockType yourClock;

   cout << "myClock = " << myClock << endl;
   cout << "yourClock = " << yourClock << endl;

   cout << "Enter the time in the form hr:min:sec = ";
   cin >> myClock;
   cout << endl;
   cout << "The new time of myClock = " << myClock << endl;

   ++myClock;
   cout << "After increase the time of myClock = " << myClock << endl;

   yourClock.setTime(13, 35, 38);
   cout << "After setting the time of yourClock = " << yourClock << endl;
   
   if (myClock == yourClock) cout << "The time of myClock and yourClock are equal." << endl;
   else cout << "The time of myClock and yourClock are not equal." << endl;

   if (myClock <= yourClock) cout << "The time of myClock is less than or equal to the time of yourClock." << endl;
   else cout << "The time of myClock is greater than the time of yourClock." << endl;

   return 0;
}