/**
    Author: Samuel Finocchio
    Date: 02/04/2018
    CopyLeft 2018

    Program: virtual_machine.h
    Description:
    Implementation of a minimal virtual machine that can run machine code.
*/

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#define MEMORY_SIZE 2048

#include <stdint.h>
#include "stack.h"

extern uint16_t memory[];
extern uint16_t instruction_register;
extern uint16_t instruction_operand;
extern uint16_t instruction_operator;
extern short unsigned int program_counter;

// Reads the instruction code gathering the operator
uint16_t decode_instruction_operator ( );

// Reads the instruction code gathering the operand
uint16_t decode_instruction_operand ( );

// Fetching step
void fetch_instruction ( );

// Decode step
void decode_instruction ( );

// Execute step
void execute_instruction ( );

// Executes an instruction of the instruction set
void execute_primitive_instruction ( );

// Loads the program in the memory
void load_program ( uint16_t program[], unsigned short int program_length );

// Executes the virtual machine
void init_virtual_machine ( );

#endif // VIRTUAL_MACHINE_H
