/***************************************************************************
 * file name   : assembler.c                                               *
 * author      : tjf & you                                                 *
 * description : This program will assemble a .ASM file into a .OBJ file   *
 *               This program will use the "asm_parser" library to achieve *
 *			     its functionality.										   * 
 *                                                                         *
 ***************************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

int main(int argc, char** argv) {

	char* filename = NULL ;					// name of ASM file
	char  program [ROWS][COLS] ; 			// ASM file line-by-line
	char  program_bin_str [ROWS][17] ; 		// instructions converted to a binary string
	unsigned short int program_bin [ROWS] ; // instructions in binary (HEX)

	// check the filename
	if (argc >= 2 && argv[1]) {
		filename = argv[1];
		for (int i = 0; i < strlen(argv[1]); i++) {
			printf("%c", argv[1][i]);
			
		}
		printf("\n");
	} else {
		fprintf(stderr, "error1: usage: ./assembler <assembly_file.asm>\n");
		return 1;
	}
	
	// read asm file
	read_asm_file(filename, program);
	
	int row = 0;
	
	while (program[row][0] != '\0') {
		char *instruction = program[row];
		char *instruction_bin_str = program_bin_str[row];
		
		parse_instruction(instruction, instruction_bin_str);
		printf("%s", instruction_bin_str);
		program_bin[row] = str_to_bin(instruction_bin_str);
		
		row++;
	}
	
	write_obj_file(filename, program_bin);
	
	return 0;
}
