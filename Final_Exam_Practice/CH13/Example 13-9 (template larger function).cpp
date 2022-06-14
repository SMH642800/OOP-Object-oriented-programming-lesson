// Exmaple 13-9: Template larger

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>

using namespace std;

class newString
{
      friend ostream& operator<<(ostream&, const newString&);
      friend istream& operator>>(istream&, newString&);

   public:
      const newString& operator=(const newString& rightStr)
      {
         if(this != &rightStr)
         {
            delete[] strPtr;
            strLength = rightStr.strLength;
            strPtr = new char[strLength + 1];
            strcopy(rightStr.strPtr);
         }
         return *this;
      }
      newString(const char *str)
      {
         strLength = strlen(str);
         strPtr = new char[strLength + 1];
         strcopy(str);
      }
      newString()
      {
         strLength = 0;
         strPtr = new char[1];
         strPtr[0] = '\0';
      }
      newString(const newString& rightStr)
      {
         strLength = rightStr.strLength;
         strPtr = new char[strLength + 1];
         strcopy(rightStr.strPtr);
      }
      ~newString()
      {
         delete[] strPtr;
      }

      char &operator[] (int index)
      {
         assert(0 <= index && index < strLength);
         return strPtr[index];
      }
      const char &operator[] (int index) const
      {
         assert(0 <= index && index < strLength);
         return strPtr[index];
      }

      bool operator==(const newString& rightStr) const
      {
         return (strcmp(strPtr, rightStr.strPtr) == 0);
      }
      bool operator!=(const newString& rightStr) const
      {
         return (strcmp(strPtr, rightStr.strPtr) != 0);
      }
      bool operator<=(const newString& rightStr) const
      {
         return (strcmp(strPtr, rightStr.strPtr) <= 0);
      }
      bool operator<(const newString& rightStr) const
      {
         return (strcmp(strPtr, rightStr.strPtr) < 0);
      }
      bool operator>=(const newString& rightStr) const
      {
         return (strcmp(strPtr, rightStr.strPtr) >= 0);
      }
      bool operator>(const newString& rightStr) const
      {
         return (strcmp(strPtr, rightStr.strPtr) > 0);
      }

   private:
      char *strcopy(const char *str)
      {
         for (int i = 0; i < strLength; i++)
            strPtr[i] = str[i];
         strPtr[strLength] = '\0';

         return strPtr;
      }
      char *strcopy(char *str1, const char *str2)
      {
         for (int i = 0; i < strlen(str1); i++)
            str1[i] = str2[i];
         str1[strlen(str1)] = '\0';

         return str1;
      }

      char *strPtr;
      int strLength;
};

ostream& operator<<(ostream& osObject, const newString& str)
{
   osObject << str.strPtr;
   return osObject;
}

istream& operator>>(istream& isObject, newString& str)
{
   char temp[81];

   isObject >> setw(81) >> temp;
   str = temp;
   return isObject;
}

template<class Type>
Type larger(Type x, Type y)
{
   if (x >= y) return x;
   else return y;
}

int main()
{
   cout << "Larger of 5 and 6 = " << larger(5, 6) << endl;
   cout << "Larger of A and B = " << larger('A', 'B') << endl;
   cout << "Larger of 5.6 and 3.2 = " << larger(5.6, 3.2) << endl;

   newString str1 = "Hello";
   newString str2 = "Happy";
   cout << "Larger of " << str1 << " and " << str2 << " = " << larger(str1, str2) << endl;

   return 0;
}