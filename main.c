/**
	Author: Samuel Finocchio
	Forked by: CybeRazor
	Date: 31/03/2019
	CopyLeft 2019

	Program: emulator.c
	Description:
	Implementation of an emulator for an invented architecture.
	
	This fork allows to execute commands given by users through stdin
*/

#include <stdint.h>
#include "stack.h"
#include "virtual_machine.h"
#include "command_interpreter.h"
#define DEBUG
#ifdef DEBUG

    #include <stdio.h>

	int main(void) {
		
		printf ( " Virtual Architecture 0.0.3 - Samuel Finocchio and CybeRazor - 2019\n\n\n" );		
		
		char input[10];
		
		while(1) {
			
			printf("\nREADY\n\n");
			
			// Used fgets() for allowing space character while reading strings
			fgets(input,11,stdin);
			
			// Truncate string at newline
			if((strlen(input)>0) && (input[strlen(input)-1]=='\n'))
				input[strlen(input)-1]='\0';
				
			if((strlen(input)==4) && (!strcmp(input,"QUIT")))
				return 0;
				
			if(input_check(input)){
				printf("\n");
				step();
				print_stack_content();
			}
			
		}
		
		return 0;
		
	}

#endif // DEBUG
