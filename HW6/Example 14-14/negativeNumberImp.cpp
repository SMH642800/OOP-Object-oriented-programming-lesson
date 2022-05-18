#include <iostream>
#include "negativeNumber.h"

using namespace std;

negativeNumber::negativeNumber()
{
    message = "Number cannot be negative";
}

negativeNumber::negativeNumber(string str)
{
    message = str + " cannot be negative";
}

negativeNumber::string what()
{
    return message;
}
