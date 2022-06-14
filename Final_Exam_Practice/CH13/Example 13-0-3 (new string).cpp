// Exmaple 13-0-3: new string 

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

int main()
{
   newString str1 = "Sunny";
   const newString str2("Warm");
   newString str3;
   newString str4;

   cout << str1 << " " << str2 << " " << str3 << " " << str4 << endl;

   if (str1 <= str2) cout << str1 << " is less than or equal to " << str2 << endl;
   else cout << str1 << " is greater than " << str2 << endl;

   cout << "Enter a string with a length of at least 7: ";
   cin >> str1;
   cout << endl;

   cout << "The new string of str1 = " << str1 << endl;

   str4 = str3 = "Birth Day";

   cout << "str3 = " << str3 << ", str4 = " << str4 << endl;

   str3 = str1;
   cout << "The new string of str3 = " << str3 << endl;

   str1 = "Bright Sky";

   str3[1] = str1[5];
   cout << "After replacing the second character of str3 with the fifth character of str1 = " << str3 << endl;

   str3[2] = str2[0];
   cout << "After replacing the third character of str3 with the first character of str2 = " << str3 << endl;

   str3[5] = 'g';
   cout << "After replacing the sixth character of str3 with character 'g' = " << str3 << endl;


   return 0;
}