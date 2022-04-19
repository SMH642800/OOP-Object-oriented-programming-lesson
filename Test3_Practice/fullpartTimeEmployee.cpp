#include <iostream>

using namespace std;

class personType
{
public:
    void print() const
    {
        cout << firstName << " " << lastName;
    }

    void setName(string first, string last)
    {
        firstName = first;
        lastName = last;
    }

    string getFName() const {return firstName;}
    string getLName() const {return lastName;}

    personType(string first = "", string last = "")
    {
        setName(first, last);
    }

private:
    string firstName, lastName;
};

class employeeType: public personType
{
public:
    /*
     *virtual function = 0 --> pure virtual function
     *留給後面衍生的子類別去自行定義function的實作內容
     */
    virtual void print() const = 0;
    virtual double calculatePay() const = 0;

    void setID(long id) {personID = id;}
    long getID() const {return personID;}

    employeeType(string first = "", string last = "", long id = 0):personType(first, last)
    {
        setID(id);
    }

private:
    long personID;
};

class fullTimeEmployee: public employeeType
{
public:
    void set(string first, string last, long id, double salary, double bonus)
    {
        setName(first, last);
        setID(id);
        setSalary(salary);
        setBonus(bonus);
    }

    void setSalary(double salary) {empSalary = salary;}
    double getSalary() const {return empSalary;}
    void setBonus(double bonus) {empBonus = bonus;}
    double getBonus() const {return empBonus;}

    void print() const
    {
        cout << "ID: " << getID() << endl;
        cout << "Name: ";
        personType::print();
        cout << endl;
        cout << "Wages: $" << calculatePay() << endl;
    }

    double calculatePay() const {return empSalary + empBonus;}

    fullTimeEmployee(string first = "", string last = "", long id = 0,
                     double salary = 0, double bonus = 0):employeeType(first, last, id)
    {
        setSalary(salary);
        setBonus(bonus);
    }

private:
    double empSalary, empBonus;
};

class partTimeEmployee: public employeeType
{
public:
    void set(string first, string last, long id, double rate, double hours)
    {
        setName(first, last);
        setID(id);
        setPayRate(rate);
        setHoursWorked(hours);
    }

    double calculatePay() const {return payRate*hoursWorked;}

    void setPayRate(double rate) {payRate = rate;}
    double getPayRate() const {return payRate;}
    void setHoursWorked(double hours) {hoursWorked = hours;}
    double getHoursWorked() const {return hoursWorked;}

    void print() const
    {
        cout << "ID: " << getID() << endl;
        cout << "Name: ";
        personType::print();
        cout << endl;
        cout << "Wages: $" << calculatePay() << endl;
    }

    partTimeEmployee(string first = "", string last = "", long id = 0,
                     double rate = 0, double hours = 0):employeeType(first, last, id)
    {
        setPayRate(rate);
        setHoursWorked(hours);
    }

private:
    double payRate, hoursWorked;
};

int main()
{
    fullTimeEmployee newEmp("John", "Smith", 75, 56000, 5700);
    partTimeEmployee tempEmp("Andy", "Turner", 275, 15.5, 57);

    newEmp.print();
    cout << endl;
    tempEmp.print();

    return 0;
}
