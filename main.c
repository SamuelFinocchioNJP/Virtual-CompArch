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
        printf ( " Virtual Architecture 0.0.1 - Samuel Finocchio - 2018\n\n\n" );

        uint16_t program[] = { 0x100A, 0x1006, 0x3000, 0x2000 };
        load_program ( program, 4 );
        init_virtual_machine ( );

        for ( int i = 0; i < 4; i++ ) {
            step();
            getchar();
        }
    }

#endif // DEBUG

