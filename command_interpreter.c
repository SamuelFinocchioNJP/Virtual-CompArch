/**
	Author: Samuel Finocchio
	Forked by: CybeRazor
	Date: 31/03/2019
	CopyLeft 2019

	Program: command_interpreter.c
	Description:
	Implementation of a minimal virtual machine that can run machine code.
*/
#include "command_interpreter.h"

// Checks user input
int input_check(char input[10]){

	if((strlen(input)==3)){
		if(!strcmp(input,"POP")){
			load_instruction(0x2000);
			return 1;
		}
		else if(!strcmp(input,"ADD")){
			load_instruction(0x3000);
			return 1;
		}
		else if(!strcmp(input,"SUB")){
			load_instruction(0x4000);
			return 1;
		}
		else if(!strcmp(input,"MUL")){
			load_instruction(0x5000);
			return 1;
		}
		else if(!strcmp(input,"DIV")){
			load_instruction(0x6000);
			return 1;
		}
		else if(!strcmp(input,"MOD")){
			load_instruction(0x7000);
			return 1;
		}
		else{
			puts("ERROR: Invalid instruction");
			return 0;
		}
	}
	else if(!strncmp(input,"PUSH ",5)){
		if(push_check(input))
			return 1;
		else
			return 0;
	}
	else{
		puts("ERROR: Invalid instruction");
		return 0;
	}
}

// Checks push value
int push_check(char input[10]){
	char val_str[5];

	// Retrieving value to push
	for(int i=5; i<strlen(input); i++){
		val_str[i-5]=input[i];
	}
	
	// Checking if the value is 0, because atoi() returns 0 when it fails
	if((strlen(val_str)==1) && (val_str[0]=='0')){
		load_instruction(0x1000);
		return 1;
	}
	else{
		int val=atoi(val_str);
		// Value must be between 0 and 4095 (0x0FFF)
		if((val<=0) || (val>4095)){
			puts("ERROR: Invalid value");
			return 0;
		}
		else{
			uint16_t push_inst=(uint16_t) val;
			push_inst=push_inst+0x1000;
			load_instruction(push_inst);
			return 1;
		}
    }
}

