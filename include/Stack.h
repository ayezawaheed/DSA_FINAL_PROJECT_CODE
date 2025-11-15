#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
         // Constructor: Initializes the stack with a given size
        Stack(int size);
         // Destructor: Frees dynamically allocated memory
        virtual ~Stack();
         // Copy constructor: Creates a new stack as a copy of another stack
        Stack(const Stack& other);
        // Checks if the stack is empty
        bool empty() const;
        // Checks if the stack is full
        bool full() const;
         // Pushes a new element onto the stack
        void push(const double x);
        double pop();
         // Pop an element from the stack
        double Top() const;
        //print stack
        void  print();

    protected:

    private:
        int top;            // Index of the current top element in the stack
        int maxTop;       // Maximum allowed index for the stack (size - 1)
        double* values;  // Pointer to dynamically allocated array to store stack value
        int size;         // Total size of the stack
};

#endif // STACK_H

