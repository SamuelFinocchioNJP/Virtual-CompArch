/**
	Author: Samuel Finocchio
	Forked by: CybeRazor
	Date: 31/03/2019
	CopyLeft 2019

	Program: command_interpreter.h
	Description:
	Implementation of a minimal virtual machine that can run machine code.
*/

#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "virtual_machine.h"

// Checks user input
int input_check(char input[10]);

// Checks push value
int push_check(char input[10]);


#endif // COMMAND_INTERPRETER_H
