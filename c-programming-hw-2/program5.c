#include <stdio.h>
void swap (int a, int b) ;
int main() {
	int a = 5 ;
	int b = 10 ;
	printf ("a= %d\n", a) ;
	printf ("b= %d\n", b) ;
	swap (a, b) ;
	printf ("a= %d\n", a) ;
	printf ("b= %d\n", b) ;
	return (0);
}