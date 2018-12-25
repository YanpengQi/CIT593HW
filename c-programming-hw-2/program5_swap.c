#include <stdio.h>
void swap (int a, int b) {
	int c = 0 ;
	c = a ; /* swap values of a and b */
	a = b ;
	b = c ;
	printf ("a= %d\n", a) ;
	printf ("b= %d\n", b) ;
	return ;
}