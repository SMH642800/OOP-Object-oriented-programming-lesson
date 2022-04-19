#include <iostream>

using namespace std;

class classExample
{
public:
    void setX(int a) {x = a;}
    void print() const {cout << "x= " << x << endl;}
    classExample() {x=9999;}
private:
    int x;
};

int main()
{
    /*
    int *list;
    list = new int[5];

    for(int i = 0; i < 5; i++){
        list[i] = i*i;
    }

    for(int i = 0; i < 5; i++){
        cout << list[i] << " ";
    }
    */

    /*
    int num1, num2;
    int *numPtr = &num2;

    num1 = 100;
    num2 = 200;

    int temp;
    cin >> temp;
    switch(temp)
    {
    case 1:
        numPtr = &num1;
        cout << num1 << " " << &num1 << endl;
        cout << num2 << " " << &num2 << endl;
        cout << *numPtr << " " << numPtr << " " << &numPtr << endl;
        break;
    case 2:
        *numPtr = num1;
        cout << num1 << " " << &num1 << endl;
        cout << num2 << " " << &num2 << endl;
        cout << *numPtr << " " << numPtr << " " << &numPtr << endl;
        break;
    }
    */

    classExample *cExpPtr;
    classExample cExpObject;
    cExpPtr = &cExpObject;
    cExpPtr->setX(5);
    cExpPtr->print();


    return 0;
}
