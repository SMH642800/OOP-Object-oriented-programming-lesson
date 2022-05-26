#include <iostream>

using namespace std;

void decToBinIterative(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{
    int decimalNum;
    int base;

    base = 2;

    cout << "Enter number in decimal: ";
    cin >> decimalNum;
    cout << endl;

    cout << "Using iterative function: " << endl << endl;
    cout << "Decimal: " << decimalNum << " --> " << "Binary: ";
    decToBinIterative(decimalNum);
    cout << endl;

    return 0;
}
