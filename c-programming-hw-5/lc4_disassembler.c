/************************************************************************/
/* File Name : lc4_disassembler.c 										*/
/* Purpose   : This file implements the reverse assembler 				*/
/*             for LC4 assembly.  It will be called by main()			*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lc4_memory.h"

int reverse_assemble (row_of_memory* memory)
{
	int Rd;
	int Rt;
	int Rs;
	int sign;
	short unsigned int imm;
	char* assembly;
	short unsigned int tmp;
	row_of_memory* cur;


	while ((cur = search_opcode(memory, 0x0001)) != NULL) {
		//printf("%x\n", cur->contents);  test input

		// may need to add casr (char*)
		assembly = malloc(17 * sizeof(char));
		cur->assembly = malloc(17 * sizeof(char));

		// can not allocate memory for assembly
		if (assembly == NULL) {
			return -1;
		}

		tmp = cur->contents << 4;
		Rd = tmp >> 13;

		tmp = cur->contents << 7;
		Rs = tmp >> 13;

		tmp = cur->contents << 13;
		Rt = tmp >> 13;

		tmp = cur->contents << 10;
		sign = tmp >> 13;

		tmp = cur->contents << 10;
		imm = tmp >> 15;

		// check imm state
		if (imm == 1) {
			tmp = cur->contents << 11;
			imm = tmp >> 11;

			if (imm > 15) {
				imm = 16 - (imm & 0b0000000000001111);
				sprintf(assembly, "ADD R%d, R%d, #-%d", Rd, Rs, imm);
				strcpy(cur->assembly, assembly);
				free(assembly);
				continue;
			}

			// update cur->assembly
			sprintf(assembly, "ADD R%d, R%d, #%d", Rd, Rs, imm);
			strcpy(cur->assembly, assembly);

			free(assembly);
			continue;
		}

		switch(sign) {
			case 0:
				sprintf(assembly, "ADD R%d, R%d, R%d", Rd, Rs, Rt);
				// printf("built assembly string\n");
				strcpy(cur->assembly, assembly);
				break;

			case 1:
				sprintf(assembly, "MUL R%d, R%d, R%d", Rd, Rs, Rt);
				// printf("built assembly string\n");
				strcpy(cur->assembly, assembly);
				break;

			case 2:
				sprintf(assembly, "SUB R%d, R%d, R%d", Rd, Rs, Rt);
				// printf("built assembly string\n");
				strcpy(cur->assembly, assembly);
				break;

			case 3:
				sprintf(assembly, "DIV R%d, R%d, R%d", Rd, Rs, Rt);
				// printf("built assembly string\n");
				strcpy(cur->assembly, assembly);
				break;

		}
		free(assembly);
	}

	return 0;
}
