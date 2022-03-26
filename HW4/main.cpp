#include <iostream>
#include <string>
#include "personType.h"
#include "partTimeEmployee.h"

using namespace std;
int main()
{

    partTimeEmployee newEmp("John", "Smith", 20, 67);

    cout << endl;
    newEmp.print();

    return 0;
}
