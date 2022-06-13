// Exmaple 16-3: binary search

#include <iostream>

using namespace std;

int binarySearch(const int list[], int listLength, int searchItem)
{
   int first = 0;
   int last = listLength - 1;
   int mid;
   bool found = false;

   while (first <= last && !found) {
      mid = (first+last) / 2;
      
      if(list[mid] == searchItem) found = true;
      else if (list[mid] > searchItem) last = mid - 1;
      else first = mid + 1;
   }

   if (found) return mid;
   else return -1;
}

int main()
{
   int list[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int searchNum;
   cout << "Enter the number of lists you want to search (0~9): ";
   cin >> searchNum;

   int index = binarySearch(list, 10, searchNum);
   cout << "The index is " << index << endl;

   return 0;
}
