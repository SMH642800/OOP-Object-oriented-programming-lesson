#ifndef NEGATIVENUMBER_H_INCLUDED
#define NEGATIVENUMBER_H_INCLUDED

#include <iostream>
using namespace std;

class negativeNumber
{
public:
    negativeNumber();
    negativeNumber(string);
    string what() const;

private:
    string message;
};

#endif // NEGATIVENUMBER_H_INCLUDED
