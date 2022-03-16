#include<iostream>
using namespace std;

class Billboard
{
private:
    string title;
public:
    void setTitle(string a) {title = a;}
    string getTitle() {return title;}
    Billboard(string b) {setTitle(b);}  //construct (parameterized)
};

int main()
{
    Billboard bill("Top 3 songs of 2022");
    cout << bill.getTitle() << endl;

    return 0;
}
