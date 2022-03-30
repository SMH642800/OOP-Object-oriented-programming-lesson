#include <iostream>
#include <string>
using namespace std;

class personType
{
public:
    void print() const{
        cout << firstName << " " << lastName;
    }

    void setName(string first, string last){
        firstName = first;
        lastName = last;
    }

    string getFirstName() const{
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    personType(string first = "NULL", string last = "NULL"){
        firstName = first;
        lastName = last;
    }

private:
    string firstName;
    string lastName;
};

class partTimeEmployee: private personType
{
public:
    void print() const{
        personType::print();
        cout << "'s wages are: $" << calculatePay() << endl;
    }

    double calculatePay() const{
        return (payRate * hoursWorked);
    }

    void setNameRateHours(string first, string last, double rate, double hours) {
        personType::setName(first, last);
        payRate = rate;
        hoursWorked = hours;
    }

    partTimeEmployee(string first = "NULL", string last = "NULL", double rate = 0, double hours = 0): personType(first, last){
        if(rate >= 0) payRate = rate;
        else payRate = 0;

        if(hours >= 0) hoursWorked = hours;
        else hoursWorked = 0;
    }

private:
    double payRate;
    double hoursWorked;
};

int main()
{
    personType newPerson2("Steve", "Job");
    personType newPerson;
    partTimeEmployee newEmp("John", "Smith", 20, 67);
    partTimeEmployee newEmp2;

    newPerson2.print();
    cout << endl;
    newPerson.print();
    cout << endl;
    newEmp.print();
    newEmp2.print();

    return 0;
}
