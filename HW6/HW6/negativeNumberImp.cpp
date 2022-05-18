#include <iostream>
#include "negativeNumber.h"
#include <string>

using namespace std;

negativeNumber::negativeNumber()
{
    message = "Number cannot be negative";
}

negativeNumber::negativeNumber(string str)
{
    message = str + " cannot be negative";
}

string negativeNumber::what()
{
    return message;
}
