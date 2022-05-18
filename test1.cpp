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

    int row=0, col=0;

    cout << "Enter row size:";
    cin >> row;
    cout << "\ncol:";
    cin >> col;

    int *p_board[row];
    for (int i=0; i < row; i++)
        p_board[i] = new int[col];

    for (int i=0; i < row; i++)
    {
        for (int j=0; j < col; j++)
        {
            p_board[i][j] = j;
            cout << p_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    int **p_p_board;
    p_p_board = new int* [row];
    for (int i=0; i < row; i++)
        p_p_board[i] = new int[col];

    for (int i=0; i < row; i++)
    {
        for (int j=0; j < col; j++)
        {
            p_p_board[i][j] = j;
            cout << p_p_board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
