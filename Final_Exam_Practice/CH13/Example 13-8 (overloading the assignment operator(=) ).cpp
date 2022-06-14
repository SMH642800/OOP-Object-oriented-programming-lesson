// Exmaple 13-8: overloading the assignment operator (=)

#include <iostream>
#include <iomanip>

using namespace std;

class cAssignmentOprOverload
{
   public:
      void inserEnd(int item)
      {
         if (length == maxSize) cout << "List is full" << endl;
         else list[length++] = item;
      }
      void destroyList()
      {
         delete[] list;
         list = nullptr;
         length = 0;
         maxSize = 0;
      }
      void print() const
      {
         if (length == 0)
            cout << "The list is empty" << endl;
         else{
            for (int i = 0; i < length; i++)
               cout << list[i] << " ";
            cout << endl;
         }
      }
      cAssignmentOprOverload(int size = 0)
      {
         maxSize = size;
         length = 0;
         if(maxSize == 0) list = nullptr;
         else list = new int[maxSize];
      }

      const cAssignmentOprOverload& operator=(const cAssignmentOprOverload& otherList)
      {
         if (this != &otherList)
         {
            delete [] list;
            maxSize = otherList.maxSize;
            length = otherList.length;

            list = new int[maxSize];
            for (int i = 0; i < length; i++){
               list[i] = otherList.list[i];
            }
         }

         return *this;
      }

   private:
      int maxSize, length;
      int *list;
};

int main()
{
   cAssignmentOprOverload intList1(10);
   cAssignmentOprOverload intList2;
   cAssignmentOprOverload intList3;

   int number;

   cout << "Enter 5 integers: ";
   for (int i = 0; i < 5; i++){
      cin >> number;
      intList1.inserEnd(number);
   }
   cout << endl;

   cout << "intList1: ";
   intList1.print();
   
   intList3 = intList2 = intList1;

   cout << "intList2: ";
   intList2.print();

   intList2.destroyList();

   cout << endl;
   cout << "After destroy intList2: ";
   intList2.print();
   cout << "After destroy intList2, intList1: ";
   intList1.print();
   cout << "After destroy intList2, intList3: ";
   intList3.print();

   cout << endl;

   return 0;
}
