#include<iostream>
#include<string>
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

class partTimeEmployee: public personType
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

    partTimeEmployee(): personType(){
        payRate = 0;
        hoursWorked = 0;
    }

    partTimeEmployee(string first, string last, double rate, double hours): personType(first, last){
        if(rate >= 0) payRate = rate;
        else payRate = 0;

        if(hours >= 0) hoursWorked = hours;
        else hoursWorked = 0;
    }

private:
    double payRate;
    double hoursWorked;
};

class dataType
{
private:
    int dMonth, dDay, dYear;

public:
    void setData(int month, int day, int year){
        dMonth = month;
        dDay = day;
        dYear = year;
    }

    int getDay() const {
        return dDay;
    }

    int getMonth() const {
        return dMonth;
    }

    int getYear() const {
        return dYear;
    }

    void printData() const{
        cout << dMonth << "-" << dDay << "-" << dYear;
    }

    dataType(int month = 1, int day = 1, int year = 1900){
        dMonth = month;
        dDay = day;
        dYear = year;
    }
};

class personalInfoType: public partTimeEmployee
{
private:
    partTimeEmployee name;
    dataType birthday;
    int personID;

public:
    void setpersonalInfo(string first, string last, double rate, double hours, int month, int day, int year, int ID){
        name.setNameRateHours(first, last, rate, hours);
        birthday.setData(month, day, year);
        personID = ID;
    }

    void printpersonalInfo() const {
        name.print();
        cout << "'s date of birth is : ";
        birthday.printData();
        cout << endl;
        cout << "and personal ID is : " << personID << endl;
    }

    personalInfoType(string first = "NULL", string last = "NULL", double rate = 0, double hours = 0, int month = 1, int day = 1, int year = 1900, int ID = 0)
        : name(first, last, rate, hours), birthday(month, day, year)
    {
        personID = ID;
    }
};

int main()
{
    personType newPerson("Steve", "Job");
    partTimeEmployee newEmp("John", "Smith", 20, 67);
    dataType newYear(1, 1, 2022);
    personalInfoType newPerson2("Hsieh", "MengHao", 25, 60, 8, 1, 2000, 6);

    newPerson.print();
    cout << endl;
    newYear.printData();
    cout << endl;
    newPerson2.printpersonalInfo();
    cout << endl;

    personType emptyPerson;
    partTimeEmployee emptyEmp;
    dataType emptyYear;
    personalInfoType emptyPerson2;

    emptyPerson.print();
    cout << endl;
    emptyEmp.print();
    emptyYear.printData();
    cout << endl;
    emptyPerson2.printpersonalInfo();

    return 0;
}
