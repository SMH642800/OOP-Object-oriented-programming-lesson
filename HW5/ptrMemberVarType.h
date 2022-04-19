#ifndef PTRMEMBERVARTYPE_H_INCLUDED
#define PTRMEMBERVARTYPE_H_INCLUDED

#include <iostream>

class ptrMemberVarType
{
public:
    void print() const;
    // Function to output the data stored in the array p.

    void insertAt(int index, int num);
    // Function to insert num into the array p at the position specified by index.
    // If index is out of bounds, the program is terminated.
    // If index is within bounds, but greater than the index of the last item in the list, num is added at the end of the list.

    ptrMemberVarType(int size = 10);
    // Constructor
    // Creates an array of the size specified by the parameter size; the default array size is 10.

    ~ptrMemberVarType();
    // Destructor
    // Deallocates the memory space occupied by the array p.

    ptrMemberVarType(const ptrMemberVarType &otherObject);
    // Copy constructor
    // This is Deep Copy

private:
    int maxSize;
    int length;
    int *p;
};

#endif // PTRMEMBERVARTYPE_H_INCLUDED
