/**************************************************************
 * file name   : my_string.c                                  *
 * author      : tjf & you                                    *
 * description : this C-file defines the functions previously *
 *               declared in the my_string.h header file      *
 *                                                            *
 *                                                            *
 **************************************************************
 *
 */

#include "my_string.h"

// strlen functions takes in a pointer to a string and return its length
//
size_t2 my_strlen  (const char *str) {

	size_t2 len = 0 ;
	while (str[len] != '\0') {  // count up to the first NULL
		len++ ; 
	}
	return (len) ;

}

size_t2 my_strlen2 (const char *str) {

	const char* s;
	for (s = str; *s; ++s) ;
	return (s - str);

}


/* CIT 593 students: TODO: implement the remaining string functions
   that were declared in my_string.h */
/* functions to copy a string */

char* my_strcpy  (char *dest, const char *src) {
	int len = (int)my_strlen(src);
	for (int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
	
	dest[len] = '\0';
	
	return dest;
}
char* my_strcpy2 (char *dest, const char *src) {
	const char* s;
	char* t = dest;
	for (s = src; *s; ++s, t++) {
		*t = *s;
	}
	
	*t = '\0';
	
	return dest;
}

/* functions to search a string */

char* my_strchr  (const char *str, int c) {
	int len = (int)my_strlen(str);
	
	for (int i = 0; i < len; i++) {
		if (c == (int)str[i]) {
			return (char *) &str[i];
		}
	}
	
	return (char*) '\0';
}
char* my_strchr2 (const char *str, int c) {
	const char* s;
	
	for (s = str; *s; s++) {
		if (c == (int) *s) {
			return (char*) s;
		}
	}
	
	return (char*) '\0';
}

/* functions to concatenate string */

char* my_strcat  (char *dest, const char *src) {
	int len_src = (int)my_strlen(src);
	int len_dest = (int)my_strlen(dest);
	
	int start = len_dest;
	int end = start + len_src;
	
	for (int i = start; i < start + end; i++) {
		dest[i] = src[i - start];
	}
	
	dest[end] = '\0';
	
	return dest;
	
}
char* my_strcat2 (char *dest, const char *src) {
	const char* s;
	char *t = dest + my_strlen(dest);

	for(s = src; *s; s++, t++) {
		*t = *s;
	}

	*t = '\0';

	return dest;
}

/* functions to compare two strings */

int strcmp  (const char *str1, const char *str2) {
	int str1_len = (int)my_strlen(str1);
	int str2_len = (int)my_strlen(str2);

	int res = 0;

	for (int i = 0; i < str1_len + 1; i++) {
		if ((int)str1[i] != (int)str2[i]) {
			res = (int)str1[i] - (int)str2[i];
		}
	}

	return res;
}

int strcmp2 (const char *str1, const char *str2) {
	const char* string1;
	const char* string2 = str2;

	int res = 0;

	for (string1 = str1; *string1; string1++, string2++) {
		if ((int) *string1 != (int) *string2) {
			res = (int) *string1 - (int) *string2;
			return res;
		}
	}

	return (int) *string1 - (int) *string2;
}

/* function to reverse the contents of the string */
char* my_strrev (char *str) {
	int len = (int)my_strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}

	return str;
}

/* function to convert each character of the passed in string to the
opposite case */
char* my_strccase (char* str) {
	int len = (int)my_strlen(str);
	for (int i = 0; i < len; i++) {
		int ascii = str[i];
		if (ascii >= 65 && ascii <= 90) {
			str[i] += 32;
		} else if (ascii >= 97 && ascii <= 122) {
			str[i] -= 32;
		}
	}

	return str;
}

/* breaks string str into a series of tokens */
char* my_strtok (char *str, const char *delim) ;
