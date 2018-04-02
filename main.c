/**
    Author: Samuel Finocchio
    Date: 27/03/2018
    CopyLeft 2018

    Program: stack.c
    Description:
    Implementation of a simple and linear data structure with push and pop operations.
*/

// #include "stack.h"

#define DEBUG
#ifdef DEBUG
    #include <stdio.h>

    int main() {
        printf("Empty: %c\n", stack_empty() ? 'T' : 'F' );
        stack_push(100);
        stack_push(120);
        printf("Empty: %c\n", stack_empty() ? 'T' : 'F' );
        printf("POP: %d\n", stack_pop());
        printf("POP: %d\n", stack_pop());
        printf("PUSH 11 and 8\n");
        stack_push(11);
        stack_push(8);
        stack_push(stack_pop() + stack_pop());
        printf("ADD %d\n", stack_pop());
        printf("Empty: %c", stack_empty() ? 'T' : 'F' );
    }

#endif // DEBUG

