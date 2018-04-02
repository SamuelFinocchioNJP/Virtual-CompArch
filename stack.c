/**
    Author: Samuel Finocchio
    Date: 27/03/2018
    CopyLeft 2018

    Program: stack.h
    Description:
    Implementation of a simple and linear data structure with push and pop operations.
*/


#define STACK_SIZE 100

#include "stack.h"

unsigned short int _stack_pointer = 0;
int _stack [STACK_SIZE];

// Checks weather the stack if full
bool stack_full ()
{
    if( _stack_pointer >= STACK_SIZE )
        return true;
    return false;
}

// Pushes an item on top of the stack
bool stack_push ( int value )
{
    if( !stack_full () )
        return _stack[_stack_pointer++] = value;
    return false;
}

// Checks weather the stack is empty
bool stack_empty ( void )
{
    return _stack_pointer <= 0;
}

// Pulls an item out of the stack
int stack_pop ( void )
{
    if( !stack_empty() ) {
        return _stack[--_stack_pointer];
    }
}
