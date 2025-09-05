// Author: J. Woychuk

// Description: This file defines class 'myArray', including a specified constructor, a destructor,
// and subscript ([]) overloading.

#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

class myArray {
public:
    // Define a getter (access) function to return the pointer 'first' defined below.
    int* getFirst() const { return first; }

    // Define attribute 'length' to define the length of the array and a specified constructor
    // to assign this length to the array and allocate memory for it
    // (https://www.geeksforgeeks.org/cpp/cpp-malloc/).
    int m_length;

    myArray (int length)
        : m_length { length }
        , first { (int*)malloc(sizeof(int)*length) }
    {
        // Check whether the memory block was initialized for the array.
        // (https://www.geeksforgeeks.org/cpp/cpp-malloc/).
        if (first == NULL) {
            cout << "A null pointer has been returned.";
        }

        else {
        cout << "Memory has been allocated at address " << first << ".\n" << endl;
        }
    }

    // Define a destructor to destroy myArray objects.
    ~myArray() { free(first); }

    // Overload the subscript ([]) operator 
    // (https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/).
    int& operator[] (int index) { return *(first + index); }

private:
    // Define a private int pointer named first. This pointer will point to the first element's location
    // in memory.
    int* first;
};