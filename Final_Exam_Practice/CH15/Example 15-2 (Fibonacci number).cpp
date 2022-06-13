// Exmaple 15-2: Fibonacci number

#include <iostream>

using namespace std;

int rFibNum(int a, int b, int n)
{
   if (n == 1) return a;
   else if (n == 2) return b;
   else return rFibNum(a, b, n-1) + rFibNum(a, b, n-2);
}

int main()
{
   int firstFibNum, secondFibNum, nth;

   cout << "First Fibonacci number: ";
   cin >> firstFibNum;

   cout << "Second Fibonacci number: ";
   cin >> secondFibNum;

   cout << "Enter Position of the desired Fibonacci number: ";
   cin >> nth;

   cout << "The Fibonacci number at position " << nth << " is: " << rFibNum(firstFibNum, secondFibNum, nth) << endl;

   return 0;
}
