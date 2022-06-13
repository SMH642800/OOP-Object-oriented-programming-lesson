// Exmaple 16-5: vector class

#include <iostream>
#include <vector>

using namespace std;


int main()
{
   vector<int> intList;
   unsigned int i;

   intList.push_back(24);
   intList.push_back(39);
   intList.push_back(90);
   intList.push_back(66);

   cout << "List: ";
   for(i=0; i<intList.size(); i++){
      cout << intList[i] << " ";
   }
   cout << endl;

   for(i=0; i<intList.size(); i++){
      intList[i] = intList[i]*2;
   }
   
   cout << "After double element, List: ";
   for(i=0; i<intList.size(); i++){
      cout << intList[i] << " ";
   }
   cout << endl;

   return 0;
}
