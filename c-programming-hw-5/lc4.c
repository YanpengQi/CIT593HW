/************************************************************************/
/* File Name : lc4.c 													*/
/* Purpose   : This file contains the main() for this project			*/
/*             main() will call the loader and disassembler functions	*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lc4_memory.h"
#include "lc4_loader.h"
#include "lc4_disassembler.h"

/* program to mimic pennsim loader and disassemble object files */

int main (int argc, char** argv) {

	/**
	 * main() holds the linked list &
	 * only calls functions in other files
	 */

	char* filename;
	FILE* file;

	/* step 1: create head pointer to linked list: memory 	*/
	row_of_memory* memory = NULL ;


	/* step 2: determine filename, then open it		*/
	/*   TODO: extract filename from argv, pass it to open_file() */
	if (argc <= 1 || argv[1] == NULL) {
		fprintf(stderr, "error1: usage:./lc4 <object_file.obj>\n");
		return 1;
	}

	filename = argv[1];
	file = open_file(filename);

	/* step 3: call function: parse_file() in lc4_loader.c 	*/
	/*   TODO: call function & check for errors		*/

	int parse_state = parse_file(file, &memory);
	if (parse_state != 0) {
		fprintf(stderr, "error2: parse_file() function failed\n");
		return 2;
	}

	/* step 4: call function: reverse_assemble() in lc4_disassembler.c */
	/*   TODO: call function & check for errors		*/

	int reverse_state = reverse_assemble(memory);
	if (reverse_state != 0) {
		fprintf(stderr, "error3: reverse_assemble() function failed\n");
		return 3;
	}

	/* step 5: call function: print_list() in lc4_memory.c 	*/
	/*   TODO: call function 				*/

	print_list(memory);

	/* step 6: call function: delete_list() in lc4_memory.c */
	/*   TODO: call function & check for errors		*/

	int delete_state = delete_list(&memory);
	if (delete_state != 0) {
		fprintf(stderr, "error4: delete_list() function failed\n");
		return -1;
	}

	/* only return 0 if everything works properly */
	return 0 ;
}
