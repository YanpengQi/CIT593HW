/***************************************************************************
 * file name   : asm_parser.c                                              *
 * author      : tjf & you                                                 *
 * description : the functions are declared in asm_parser.h                *
 *               The intention of this library is to parse a .ASM file     *
 *			        										               * 
 *                                                                         *
 ***************************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

/* to do - implement all the functions in asm_parser.h */

int read_asm_file(char* filename, char program [ROWS][COLS]) {
	// read file
	FILE *file = fopen(filename, "r");

	// check file
	if (file == NULL) {
		fprintf(stderr, "error2: read_asm_file() failed\n");
		return 2;
	}

	for (int i = 0; i < 100; ++i) {
		char line [COLS];
		if (fgets(line, COLS, file) != NULL) {
			int wordlen;
			for (int j = 0; j < COLS; ++j) {
				if (line[j] == '\n' || line[j] == '\r') {
					wordlen = j;
				}
			}

			for (int j = 0; j < wordlen; ++j) {
				program[i][j] = line[j];
			}
			program[i][wordlen] = '\0';
		} else {
			program[i][0] = '\0';
		}
	}

	// // test
	// for(int i=0 ; i < 8; ++i){
	//    	for(int j = 0; j < 255 ; ++j){
	//         printf("%c", program[i][j]);
	//     }
	//         printf("\n");
	// }

	fclose(file);
	return 0;

}

int parse_instruction(char* instr, char* instr_bin_str) {
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error3: parse_instruction() failed.\n") ;
		return 3 ;
	}

	char *token = NULL;

	// get the first toke
	token = strtok(instr, ", ");
	// decide its opcode
	if (strcmp(token, "ADD") == 0) {
	    
	    parse_add(instr, instr_bin_str);

	} else if (strcmp(token, "SUB") == 0) {

		parse_sub(instr, instr_bin_str);
	
	} else if (strcmp(token, "DIV") == 0) {

		parse_div(instr, instr_bin_str);

	} else if (strcmp(token, "MUL") == 0) {

		parse_mul(instr, instr_bin_str);
	
	} else if (strcmp(token, "AND") == 0) {

		parse_and(instr, instr_bin_str);
	
	}  else if (strcmp(token, "OR") == 0) {

		parse_or(instr, instr_bin_str);

	} else if (strcmp(token, "XOR") == 0) {

		parse_xor(instr, instr_bin_str);
	}


	// while( token != NULL ) {
 //      printf( " %s\n", token );
    
 //      token = strtok(NULL, s);
 //   }
   
   	return 0;
}

int parse_add(char* instr, char* instr_bin_str) {
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_add() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0001";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}
	
	char *token = NULL;
	token = strtok(NULL, ", ");
	// the second element pass in
	// printf("add: first reg : %c\n", token[1]);
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	// printf("add: second reg : %c\n", token[1]);
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "000";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");
	// printf("add: third reg : %c\n", token[1]);
	parse_reg(token[1], instr_bin_str);

	return 0;

}

int parse_sub(char* instr, char* instr_bin_str) {
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_sub() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0001";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}

	char *token = NULL;
	token = strtok(NULL, ", ");
	// the second element pass in
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "010";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");

	parse_reg(token[1], instr_bin_str);

	return 0;
}

int parse_mul(char* instr, char* instr_bin_str) {	
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_mul() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0001";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}

	char *token = strtok(NULL, ", ");
	// the second element pass in
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "001";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	return 0;
}

int parse_div(char* instr, char* instr_bin_str) {	
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_div() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0001";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}

	char *token = strtok(NULL, ", ");
	// the second element pass in
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "011";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	return 0;
}

int parse_and(char* instr, char* instr_bin_str) {
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_and() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0101";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}

	char *token = strtok(NULL, ", ");
	// the second element pass in
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "000";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	return 0;	
}

int parse_or(char* instr, char* instr_bin_str) {
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_or() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0101";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}

	char *token = strtok(NULL, ", ");
	// the second element pass in
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "010";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	return 0;	
}

int parse_xor(char* instr, char* instr_bin_str) {
	if (instr == NULL || instr == '\0') {
		fprintf(stderr, "error4: parse_xor() failed.\n");
		return 4;
	}

	char *opcode_start4 = "0101";
	for (int i = 0; i < 4; ++i) {
		instr_bin_str[i] = opcode_start4[i];
	}

	char *token = strtok(NULL, ", ");
	// the second element pass in
	parse_reg(token[1], instr_bin_str);

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	char *opcode_mid3 = "011";
	for (int i = 0; i < 3; ++i) {
		instr_bin_str[i + 10] = opcode_mid3[i];
	}

	token = strtok(NULL, ", ");
	parse_reg(token[1], instr_bin_str);

	return 0;	
}

int parse_reg(char reg_num, char* instr_bin_str) {

	if (reg_num == '\0') {
		fprintf(stderr, "error5: parse_reg() failed.\n");
		return 5;
	}

	const char *R;

	switch(reg_num) {
		case '0':
			R = "000";
			break;
		case '1':
			R = "001";
			break;
		case '2':
			R = "010";
			break;
		case '3':
			R = "011";
			break;
		case '4':
			R = "100";
			break;
		case '5':
			R = "101";
			break;
		case '6':
			R = "110";
			break;
		case '7':
			R = "111";
			break;
	}
	printf("%c\n", reg_num);
	printf("%s\n", R);

	strcat(instr_bin_str, R);

	return 0;
}

unsigned short int str_to_bin (char* instr_bin_str) {
	// get the binary number
	unsigned short int binary_num;
	binary_num = strtol(instr_bin_str, NULL, 2);

	printf("The number is %x\n", binary_num);

	// if (binary_num == 0) {
	// 	printf("error6: function str_to_bin() failed\n");
	// 	return 6;		
	// }

	return binary_num;
}

int write_obj_file (char* filename, unsigned short int program_bin[ROWS]) {
	const char *index = strchr(filename, '.');

	filename[index - filename + 1] = 'o';
	filename[index - filename + 2] = 'b';
	filename[index - filename + 3] = 'j';

	FILE *obj = fopen("tmp", "wb");
		
	if (obj == NULL) {
		fprintf(stderr, "error7: write_obj_file() failed.\n");
		return 7;
	}

	int size = sizeof(unsigned short int);
	unsigned short int code = 0xCADE;
	fwrite(&code, size, 1, obj);

	unsigned short int code1 = 0x0000;
	fwrite(&code1, size, 1, obj);

	int count = 0;
	while(program_bin[count]) {
		count++;
	}

	fwrite(&count, size, 1, obj);
	fwrite(program_bin, size, count, obj);
	fclose(obj);

	// swap
	unsigned short int tmp[1];
	FILE *obj_1 = fopen("tmp", "rb");
	FILE *final = fopen(filename, "wb");

	if (obj_1 == NULL || final == NULL) {
		fprintf(stderr, "error7: write_obj_file() failed.\n");
		return 7;
	}

	while(fread(tmp, size, 1, obj_1)) {
		*tmp = (*tmp >> 8) | (*tmp << 8);
		fwrite(&tmp, size, 1, final);
	}


	fclose(final);
	fclose(obj_1);

	return 0;
}
