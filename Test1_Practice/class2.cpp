#include<iostream>
using namespace std;

class Billboard
{
private:
    string title;

public:
    void setTitle(string x) {title = x;}
    string getTitle() {return title;}
};

int main()
{
    Billboard bill;
    bill.setTitle("Top5 songs of 2022");
    cout << bill.getTitle() << endl;

    return 0;
}
