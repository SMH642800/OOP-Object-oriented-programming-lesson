#include <iostream>
#include <string>

using namespace std;

int main()
{
   try
   {
      int dividend, divisor=1, quotient;
      string inpStr = "The input stream is in the fail state.";

      cout << "Enter dividend: ";
      cin >> dividend;
      
      cout << "Enter divisor: ";
      cin >> divisor;

      if (divisor == 0){
         throw divisor;
      }
      else if (divisor < 0){
         throw string("Negative divisor.");
      }
      else if (!cin){
         throw inpStr;
      }

      quotient = dividend / divisor;

      cout << "Quotient: " << quotient << endl;
   }
   catch(int x)
   {
      cout << "Divisor by " << x << endl;
   }
   catch(string s)
   {
      cout << s << endl;
   }
   

   return 0;
}