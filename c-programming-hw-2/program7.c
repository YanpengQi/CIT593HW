/********************************************************
 * file name   : program7.c                             *
 * author      : Thomas Farmer                          *
 * description : Program to examine C-stack             *
 *                                                      *
 ********************************************************
*
*/

#include <stdio.h>

int main () {


	int a = 5 ;
	int* a_ptr = &a ;	/* a_ptr points to a */

	printf ("a's value     = %d \n", a) ;
	printf ("a's address   = %p \n", &a) ;
	printf ("a_ptr value   = %p \n", a_ptr) ;
	printf ("a_ptr address = %p \n", &a_ptr) ;
	printf ("a_ptr deref'ed= %d \n", *a_ptr) ;
	printf ("\n") ;
 
	int array [5] = {0, 1, 2, 3, 4};
	for (a=0; a < 5 ; a++) {

		printf (" array[%d]=%d \n", a, array[a]) ;
		printf ("&array[%d]=%p \n", a, &array[a]) ;

	}
	printf ("\n") ;


	int b = 10 ;
	int* b_ptr = &b ;	/* b_ptr points to b */
	int** b_ptr_ptr = &b_ptr ;   /* b_ptr_ptr points to b_ptr */


	printf ("b's value          = %d \n", b) ;
	printf ("b's address        = %p \n", &b) ;
	printf ("b_ptr value        = %p \n", b_ptr) ;
	printf ("b_ptr address      = %p \n", &b_ptr) ;
	printf ("b_ptr defer'ed     = %d \n", *b_ptr) ;
	printf ("b_ptr_ptr value    = %p \n", b_ptr_ptr) ;
	printf ("b_ptr_ptr address  = %p \n", &b_ptr_ptr) ;
	printf ("b_ptr_ptr deref'ed = %p \n", *b_ptr_ptr) ;
	printf ("b_ptr_ptr deref'ed defer'ed = %d \n", b) ;
	printf ("\n") ;

	return (0) ;

}