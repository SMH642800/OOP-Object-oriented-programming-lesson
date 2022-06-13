// Exmaple 16-1: Bubble sorting

#include <iostream>

using namespace std;

void bubbleSort(int list[], int length) 
{
   int temp;

   for(int i=0; i<length; i++){
      for (int j=0; j<length-i; j++){
         if(list[j] > list[j+1]){
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
         }
      }
   }
}

int main()
{
   int list[] = {20, 36,24, 65, 78, 45, 58, 90, 2, 15};

   bubbleSort(list, 10);

   cout << "After sorting: ";
   for (int i = 0; i < 10; i++){
      cout << list[i] << " ";
   }

   cout << endl;

   return 0;
}
