#include<iostream>
using namespace std;

class Gambit
{
public:
    Gambit() {cout << "Hello there, I'm in constructor." << endl;}
    ~Gambit() {cout << "Hello there, I'm destructor" << endl;}
    void display() {cout << "hello! " << endl;}
};

int main()
{
    Gambit gam;
    gam.display();

    return 0;
}
