#include <iostream>

using namespace std;

int main()
{
   try
   {
      int dividend, divisor, quotient;

      cout << "Enter dividend: ";
      cin >> dividend;
      
      cout << "Enter divisor: ";
      cin >> divisor;

      if (divisor == 0){
         throw 0;
      }

      quotient = dividend / divisor;

      cout << "Quotient: " << quotient << endl;
   }
   catch(int)
   {
      cout << "Divisor by zero." << endl;
   }
   

   return 0;
}