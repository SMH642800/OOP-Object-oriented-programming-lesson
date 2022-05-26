#include <iostream>

using namespace std;

void decToBinRecursion(int num, int base)
{

    if(num > 0){
        decToBinRecursion(num/base, base);
        cout << num % base;
    }

}

int main()
{
    int decimalNum;
    int base;

    base = 2;

    cout << "Enter number in decimal: ";
    cin >> decimalNum;
    cout << endl;

    cout << "Using recursion function: " << endl << endl;
    cout << "Decimal: " << decimalNum << " --> " << "Binary: ";
    decToBinRecursion(decimalNum, base);
    cout << endl;

    return 0;
}
