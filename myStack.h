// Author: J. Woychuk

// Description: This file defines a 'myStack' class, including a specified constructor, mostly inherited
// from class 'myArray', and push, peek, and pop functions.

#pragma once
#include "myArray.h"

class myStack : public myArray {

    private:
        // Private pointer 'top' will indicate where the 'top' of the stack is, which is the next element 
        // to be accessed.
        int* top;
    
    public:
        // Define a specified constructor for myStack using myArray's constructor
        // (https://cppscripts.com/cpp-using-parent-constructor).
        myStack (int stackMax)
        : myArray(stackMax)
        , top {nullptr}
        {
        }

        // Define member function 'push' to 
        // place the desired element into the available spot and update the top pointer to reference the 
        // new element. For this function, it will be assumed that the length of the stack is the maximum 
        // available space in the stack.
        
        void push(int element)
        {
            if (top == nullptr) {
                *getFirst() = element;
                top = getFirst();
            }

            else if ((top - getFirst()) < m_length) {
                *(top + 1) = element;
                top++;
            }

            else if ((top - getFirst()) >= m_length) { 
                cout << "Stack overflow: the stack is full. " << endl;
            }
        }

        // Define a function peek to return the value found at the top of the stack.
        int peek() {
            if (top == nullptr) {
                cout << "The stack is empty." << endl;
                
                return 0;
            }

            else {
                cout << *top << endl;
                return *top;
            }
        }

        // Define a pop function to return the value found atop the stack, clear the memory at that
        // location, and update the top pointer.
        int poppedInt;

        int pop() {

            if (top == nullptr) {
                cout << "Stack underflow: there is nothing in the stack." << endl;
            }

            else if ((top - getFirst()) > 0) {
                poppedInt = *top;
                *top = 0;
                top--;
                return poppedInt;
            }

            else if ((top - getFirst()) == 0) {
                poppedInt = *top;
                *top = 0;
                top = nullptr;
                return poppedInt;
            }

            return 0;
        }
       
};