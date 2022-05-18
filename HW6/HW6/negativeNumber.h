#ifndef NEGATIVENUMBER_H_INCLUDED
#define NEGATIVENUMBER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class negativeNumber
{
public:
    negativeNumber();
    negativeNumber(string);
    string what();

private:
    string message;
};

#endif // NEGATIVENUMBER_H_INCLUDED
