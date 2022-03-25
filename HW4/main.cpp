#include <iostream>
#include <string>
#include "personType.h"
#include "partTimeEmployee.h"

using namespace std;
int main()
{
    personType newPerson("Steve", "Job");
    partTimeEmployee newEmp("John", "Smith", 20, 67);

    newPerson.print();
    cout << endl;
    newEmp.print();

    return 0;
}
