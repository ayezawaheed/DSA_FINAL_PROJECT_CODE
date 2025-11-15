#include "Stack.h"
using namespace std;

#include <iostream>

// Constructor: Initializes the stack with the given size
Stack::Stack(int size) {
   values = new double[size]; // Dynamically allocate memory for the stack
   maxTop = size - 1;         // Set the maximum allowed index for the stack
   top = -1;                  // Set top to -1, indicating an empty stack
}

// Destructor: Frees the dynamically allocated memory
Stack::~Stack() {
    delete[] values; // Delete the array to prevent memory leaks
}

// Copy Constructor: Creates a new stack as a copy of another stack
Stack::Stack(const Stack& other) {
    size = other.size; // Copy the size of the stack
    top = other.top;   // Copy the top index
    values = new double[size]; // Allocate new memory for the copied stack
    for (int i = 0; i <= top; i++) {
        values[i] = other.values[i]; // Copy the elements one by one
    }
}

// Function to check if the stack is empty
bool Stack::empty() const {
    return top == -1; // Returns true if top is -1, indicating an empty stack
}

// Function to check if the stack is full
bool Stack::full() const {
    return top == maxTop; // Returns true if top equals maxTop
}

// Function to push an element onto the stack
void Stack::push(const double x) {
    if (full()) {
        cout << "The stack is full;" << endl; // Print a message if the stack is full
    } else {
        values[++top] = x; // Increment top and store the value at the new top
    }
}

// Function to pop an element from the stack
double Stack::pop() {
    if (empty()) {
        cout << "The stack is empty;" << endl; // Print a message if the stack is empty
        return 0; // Return 0
    } else {
        return values[top--]; // Return the value at the top and then decrement top
    }
}

// Function to return the top element of the stack without removing it
double Stack::Top() const {
    if (empty()) {
        cout << "The stack is empty." << endl;      // Print a message if the stack is empty
        return 0; // Return 0
    } else {
        return values[top]; // Return the value at the top
    }
}



