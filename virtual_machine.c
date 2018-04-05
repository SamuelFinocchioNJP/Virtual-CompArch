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

uint16_t memory [MEMORY_SIZE];
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
    // Executes complex instructions composing primitive instructions
    execute_primitive_instruction ( );
}

// Executes an instruction of the instruction set
void execute_primitive_instruction ( ) {
    if ( instruction_operator == INSTRUCTION_PUSH )
        stack_push( instruction_operand );

    if ( instruction_operator == INSTRUCTION_POP )
        printf ( " STACK POP %d\n", stack_pop( ) );

    if ( instruction_operator == INSTRUCTION_ADD )
        stack_push( stack_pop( ) +  stack_pop( ) );

    if ( instruction_operator == INSTRUCTION_MUL )
        stack_push( stack_pop( ) * stack_pop( ) );

    if ( instruction_operator == INSTRUCTION_SUB ) {
        uint16_t operand_top = stack_pop( );
        uint16_t operand_bottom = stack_pop( );
        stack_push( operand_top - operand_bottom );
    }

    if ( instruction_operator == INSTRUCTION_DIV ) {
        uint16_t operand_top = stack_pop( );
        uint16_t operand_bottom = stack_pop( );
        stack_push( operand_top / operand_bottom );
    }

    if ( instruction_operator == INSTRUCTION_MOD ) {
        uint16_t operand_top = stack_pop( );
        uint16_t operand_bottom = stack_pop( );
        stack_push( operand_top % operand_bottom );
    }
}

// Loads the program in the memory
void load_program ( uint16_t program[], unsigned short int program_length ) {
    for ( int i = 0; i < program_length; i++ ) {
        memory [i] = program[i];
    }
}

// Executes a step for the virtual machine
void step ( ) {
    fetch_instruction();
    decode_instruction();
    execute_instruction();

    printf ( " PC: %d | IR: 0x%x ", program_counter, instruction_register );
}

// Executes the virtual machine
void init_virtual_machine ( ) {
    program_counter = 0;
    instruction_register = 0x0000;
}

