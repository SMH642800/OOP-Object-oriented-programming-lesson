#include <iostream>
#include <string>
#include "personType.h"
#include "partTimeEmployee.h"

using namespace std;
int main()
{
    personType newPer("John", "Smith");
    personType newPerson("Steve", "Job");
    partTimeEmployee newEmp("John", "Smith", 20, 67);

    cout << endl;
    newEmp.print();

    return 0;
}
