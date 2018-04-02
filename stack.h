/**
    Author: Samuel Finocchio
    Date: 27/03/2018
    CopyLeft 2018

    Program: stack.h
    Description:
    Implementation of a simple and linear data structure with push and pop operations.
*/

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

extern unsigned short int _stack_pointer;
extern int _stack[];

// Checks weather the stack if full
bool stack_full();

// Pushes an item on top of the stack
bool stack_push (int value);

// Checks weather the stack is empty
bool stack_empty (void);

// Pulls an item out of the stack
int stack_pop (void);


#endif // STACK_H
