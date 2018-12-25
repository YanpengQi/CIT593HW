#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main() {
	char my_string [100] = "I love MCIT593" ;

	printf ("String before reversal: \"%s\" \n", my_string) ;
	
	char* ptr = my_strrev(my_string) ;
	
	printf ("reversed: \"%s\" \n", my_string) ;
	
	//test whether the address is the same
	printf ("start of reversed string: \"%p\" \n", ptr) ;
	printf ("Address of the start of the reversed string(should be the same): \"%p\" \n", &my_string[0]) ;

	my_strrev(my_string) ;
	printf("reverses back: \"%s\" \n", my_string) ;
	
	printf ("Sample string before flipped: \"%s\" \n", my_string) ;

	char* ptr1 = my_strccase(my_string) ;

	printf("flips case of each character in the string: \"%s\" \n", my_string) ;
	
	//test whether the address is the same
	printf("the start of flipped string: \"%p\" \n", ptr1) ;
	printf("Address of the start of flipped string(should be the same): \"%p\" \n", &my_string[0]) ;

	my_strccase(my_string) ;
	printf("fips back: \"%s\" \n", my_string) ;

	return (0) ;
}