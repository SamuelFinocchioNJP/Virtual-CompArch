/**
    Author: Samuel Finocchio
    Date: 02/04/2018
    CopyLeft 2018

    Program: virtual_machine.c
    Description:
    Implementation of a minimal virtual machine that can run machine code.
*/

#include "virtual_machine.h"
#include "instruction_set.h"

uint16_t memory [2048];
uint16_t instruction_register;
uint16_t instruction_operand;
uint16_t instruction_operator;
short unsigned int program_counter;

// Reads the instruction code gathering the operator
uint16_t decode_instruction_operator ( ) {
    uint16_t operator_code;

    // Reads the first 4 bits in the instruction retrieving the operator code
    operator_code = ( instruction_register & 0xF000 ) >> 12;
    return operator_code;
}

// Reads the instruction code gathering the operand
uint16_t decode_instruction_operand ( ) {
    uint16_t instruction_code;

    // Reads the last 12 bits of the instruction retrieving the operand code
    // No need for shifting, the operand code being to the right side of the instruction
    instruction_code = ( instruction_register & 0x0FFF );
    return instruction_code;
}

// Fetching step
void fetch_instruction ( ) {
    // Reads the instruction from memory and saves it's code in the instruction register
    instruction_register = memory[program_counter];
    // Increments the program counter to point to the next location
    program_counter++;
}

// Decode step
void decode_instruction ( ) {
    instruction_operand = decode_instruction_operand ( );
    instruction_operator = decode_instruction_operator ( );
}

// Execute step
void execute_instruction ( ) {
    if ( instruction_operator == INSTRUCTION_PUSH )
        stack_push( instruction_operand );


}

// Executes an instruction of the instruction set
void execute_primitive_instruction ( );

// Loads the program in the memory
void load_program ( uint16_t program[] );

// Executes the virtual machine
void init_virtual_machine ( );

