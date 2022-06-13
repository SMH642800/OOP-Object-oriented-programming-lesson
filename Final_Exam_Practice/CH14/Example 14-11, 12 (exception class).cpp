#include <iostream>
#include <string>

using namespace std;

class divisionByZero
{
   public:
      divisionByZero() {message = "division by zero";}
      divisionByZero(string str) {message = str;}
      string what() {return message;}

   private:
      string message;
};

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
         throw divisionByZero();
         // throw divisionByZero("Found division by 0.");
      }

      quotient = dividend / divisor;

      cout << "Quotient: " << quotient << endl;
   }
   catch(divisionByZero divByZeroObject)
   {
      cout << "In the divisionByZero catch block: " << divByZeroObject.what() << endl;
   }
   

   return 0;
}