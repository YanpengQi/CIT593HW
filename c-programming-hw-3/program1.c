/**************************************************************
 * file name   : program1.c                                   *
 * author      : tjf & you                                    *
 * description : this C-file tests the functions of the       *
 *               "my_string" library                          *
 *                                                            *
 *                                                            *
 **************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main() {

	// a string we will test with
	char my_string [100] = "Tom" ;

	// test of strlen() functions 
	printf ("Sample string: \"%s\" \n", my_string) ;
	printf (" string's length: strlen()     = %lu \n",   strlen  (my_string)) ;
	printf (" string's length: my_strlen()  = %lu \n", my_strlen (my_string)) ;
	printf (" string's length: my_strlen2() = %lu \n", my_strlen2(my_string)) ;

    /* CIT 593 students: TODO: add code to test your my_string.h functions */

    // test strcpy()
	char new_string [100] ;

	printf(" copy a string literal: strcpy()              = \"%s\" \n", strcpy(new_string, "May I copy??"));
	printf(" copy a string literal: my_strcpy()           = \"%s\" \n", my_strcpy(new_string, "May I copy??"));
	printf(" copy a string literal: my_strcpy2()         = \"%s\" \n", my_strcpy2(new_string, "May I copy??")) ;

	char new_string_1 [100] = "Yes!" ;
	char new_string_dest [100] ;

    printf(" copy a string variable: strcpy()              = \"%s\" \n", strcpy(new_string_dest, new_string_1));
	printf(" copy a string variable: my_strcpy()           = \"%s\" \n", my_strcpy(new_string_dest, new_string_1));
	printf(" copy a string variable: my_strcpy2()         = \"%s\" \n", my_strcpy2(new_string_dest, new_string_1)) ;

	

	// test strchr()
	char* str1 = "I love CIT 593" ;
	int char1 = 'l' ;
	int char2 = 'o' ;
	//doesn't exist
	int char3 = 'w' ; 

	char* Ptr1 = strchr(str1, char1) ;
	char* Ptr2 = strchr(str1, char2) ;
	char* Ptr3 = strchr(str1, char3) ;
	printf("The first occurance of \'%c\' in \"%s\" is \"%s\". \n", char1, str1, Ptr1) ;
	printf("The first occurance of \'%c\' in \"%s\" is \"%s\". \n", char2, str1, Ptr2) ;
	printf("Returns \"%s\" if \'%c\' is not in \"%s\". \n", Ptr3, char3, str1) ;


	char* retPtr4 = my_strchr(str1, char1) ;
	char* retPtr5 = my_strchr(str1, char2) ;
	char* retPtr6 = my_strchr(str1, char3) ;
	printf("the first occurance of \'%c\' in \"%s\" is \"%s\". \n", char1, str1, retPtr4) ;
	printf("the first occurance of \'%c\' in \"%s\" is \"%s\". \n", char2, str1, retPtr5) ;
	printf("Returns \"%s\" if \'%c\' is not in \"%s\". \n", retPtr6, char3, str1) ;

	char* retPtr7 = my_strchr2(str1, char1) ;
	char* retPtr8 = my_strchr2(str1, char2) ;
	char* retPtr9 = my_strchr2(str1, char3) ;
	printf("the first occurance of \'%c\' in \"%s\" is \"%s\". \n", char1, str1, retPtr7) ;
	printf("the first occurance of \'%c\' in \"%s\" is \"%s\". \n", char2, str1, retPtr8) ;
	printf("Returns \"%s\" if \'%c\' is not in \"%s\". \n", retPtr9, char3, str1) ;



	// test strcat()
	char dest [100], src [100];
		
	my_strcpy(dest, "I love") ;
	my_strcpy(src, "MCIT") ;

	printf("concatenates strings: strcat()     = \"%s\" \n", 	strcat(dest, src)) ;

	my_strcpy(dest, "I love") ;
	my_strcpy(src, "MCIT") ;

	printf("concatenates strings: my_strcat()  = \"%s\" \n", my_strcat(dest, src)) ;

	my_strcpy(dest, "I love") ;
	my_strcpy(src, "MCIT") ;

	printf("concatenates strings: my_strcat2() = \"%s\" \n", my_strcat2(dest, src)) ;



	// test strcmp2()
	char* leftStr1 = "china" ;
	char* rightStr1 = "CHINA" ;

	printf("returns positive    = %d \n", strcmp(leftStr1, rightStr1)) ;
	printf("returns positive    = %d \n", strcmp2(leftStr1, rightStr1)) ;
	
	char* leftStr2 = "USA" ;
	char* rightStr2 = "usa" ;

	printf("returns negative     = %d \n", strcmp(leftStr2, rightStr2)) ;
	printf("returns negative 	 = %d \n", strcmp2(leftStr2, rightStr2)) ;
	

    char* leftStr3 = "ABC" ;
    char* rightStr3 = "ABC" ;
	printf("returns 0      = %d \n", strcmp(leftStr3, rightStr3)) ;
	printf("returns 0      = %d \n", strcmp2(leftStr3, rightStr3)) ;


	return (0) ;

}
