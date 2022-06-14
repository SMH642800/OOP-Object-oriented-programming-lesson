// Exmaple 13-10: Class Template

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

template <class elemType>
class listType
{
   public:
      bool isEmpty() const {return (length == 0);}
      bool isFull() const {return (length == maxSize);}

      int getLength() const {return length;}
      int getMaxSize() const {return maxSize;}

      void sort()
      {
         int min;
         elemType temp;
         
         for (int i = 0; i < length; i++){
            min = i;
            for (int j = i+1; j < length; j++){
               if(list[j] < list[min])
                  min = j;
            }

            temp = list[i];
            list[i] = list[min];
            list[min] = temp;
         }
      }

      void print()
      {
         for (int i = 0; i < length; ++i)
            cout << list[i] << " ";
         cout << endl;
      }

      void insertAt(const elemType& item, int index)
      {
         assert(index >= 0 && index < maxSize);
         list[index] = item;
         length++;
      }

      listType(int listSize = 50)
      {
         maxSize = listSize;
         length = 0;
         list = new elemType[maxSize];
      }
      ~listType()
      {
         delete[] list;
      }

   private:
      int maxSize, length;
      elemType *list;
};

int main()
{
   listType<int> intList1(100);
   listType<newString> stringList;

   int index;
   int number;

   cout << "Processing the integer list" << endl;
   cout << "Enter 5 integers: ";
   for (index = 0; index < 5; index++)
   {
      cin >> number;
      intList1.insertAt(number,index);
   }
   cout << endl;

   cout << "intList: ";
   intList1.print();
   cout << endl;

   intList1.sort();
   cout << "After sorting the intList1: ";
   intList1.print();
   cout << endl;

   newString str;

   cout << "Processing the string list" << endl;
   cout << "Enter 5 strings: ";
   for (index = 0; index < 5; index++)
   {
      cin >> str;
      stringList.insertAt(str, index);
   }
   cout << endl;

   cout << "stringList: ";
   stringList.print();
   cout << endl;

   stringList.sort();
   cout << "After sorting the stringList: ";
   stringList.print();
   cout << endl;

   int intListSize;
   cout << "Enter the size of the integer list: ";
   cin >> intListSize;
   cout << endl;

   listType<int> intList2(intListSize);

   cout << "Processing the integer list" << endl;
   cout << "Enter " << intListSize << " integers: ";
   for (int i = 0; i < intListSize; i++) {
      cin >> number;
      intList2.insertAt(i, number);
   }
   cout << endl;

   cout << "intList2: ";
   intList2.print();
   cout << endl;

   intList2.sort();
   cout << "After sorting the intList2: ";
   intList2.print();
   cout << endl;

   cout << "Length of the intList2: " << intList2.getLength() << endl;
   cout << "Maximum size of intList2: " << intList2.getMaxSize() << endl;

   return 0;
}