/**
    Author: Samuel Finocchio
    Date: 27/03/2018
    CopyLeft 2018

    Program: Emulator.c
    Description:
    Implementation of an emulator for an invented architecture.
*/

#include <stdint.h>
#include "stack.h"
#include "virtual_machine.h"
#define DEBUG
#ifdef DEBUG
    #include <stdio.h>

    int main() {
        printf ( " Virtual Architecture 0.0.2 - Samuel Finocchio - 2018\n\n\n" );

        uint16_t program[] = { 0x100A, 0x10A6, 0x10FF, 0x1002, 0x3000, 0x4000, 0x7000, 0x2000 };
        size_t instructions_amount = sizeof(program) / sizeof(uint16_t);
        load_program ( program, instructions_amount );
        init_virtual_machine ( );

        for ( int i = 0; i < instructions_amount; i++ ) {
            step();
            print_stack_content();
            getchar();
        }
    }

#endif // DEBUG

