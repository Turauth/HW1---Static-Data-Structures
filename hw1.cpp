// Author: J. Woychuk

// Description: This file tests classes 'myArray' and 'myStack' by instantiating a stack and
// demonstrating its functions.

#include "myArray.h"
#include "myStack.h"

int main()
{
    myStack stack{ 7 };
    
    for (int i { 7 }; i < 17; i++)
    {
        stack.push(i);
    }

    for (int i { 0 }; i < 10; i++)
    {
        stack.peek();
        stack.pop();
    }

    return 0;
}