/*****************************************/
/* Program to swap bytes in a .OBJ file  */
/* author: tjf                           */
/*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv) {

	// check arguments
	//
	if (argc<2) {
		fprintf(stderr, "usage: %s source_file.obj\n", argv[0]) ;
		return 1 ;
	}

	// create dest_filename from source_file name
	//
	char* source_file = argv[1] ; 
	char* dest_file = malloc ((strlen(source_file)+1) + 4) ;
	strcpy (dest_file, source_file) ;
	dest_file[strlen(source_file)-4] = '\0' ;
	strcat (dest_file, "_cpy.obj") ;

	printf ("source file name = %s\n", source_file) ;
	printf ("destination file name = %s\n", dest_file) ;

	FILE* src_file = fopen (source_file, "rb") ;
	FILE* des_file = fopen (dest_file, "wb") ;

	int byte1 = 0 ;
	int byte2 = 0 ;
	int flag = 0  ;

	// read in bytes from src file and write them swapped to dest_file
	//
	do {

		// read in two bytes: byte1 & byte2
		byte1 = fgetc (src_file) ;
		printf ("\tbyte1 = %x\n", byte1 ) ; 
		if (byte1 == EOF) break ;

		byte2 = fgetc (src_file) ;
		printf ("\tbyte2 = %x\n", byte2 ) ; 
		if (byte2 == EOF) {flag = 1 ; break ; } 	// this should never happen

		// 
		fputc (byte2, des_file) ;
		fputc (byte1, des_file) ;

	} while (byte1 != EOF) ;


	// check for uneven # of bytes
	if (flag == 1) {
		fprintf (stderr, "The source has an error, it contains an uneven # of bytes; bytes cannot be swapped\n") ;
		fprintf (stderr, "The source has an error, it contains an uneven # of bytes; bytes cannot be swapped\n") ;
	} else {
		printf ("Bytes sucessfully swapped, file: %s has been written\n", dest_file) ;
	}


	fclose (src_file) ;
	fclose (des_file) ;
	free (dest_file) ;

	return (flag) ;

}