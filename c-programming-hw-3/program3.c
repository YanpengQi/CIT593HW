#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main (int argc, char** argv) {
	
	int IntegerArr[argc];
	int count = 0;
	int IntStore;
	int isInt;
	char StringArr[250] = "";
	char* StringArrPtr = StringArr;

	for (int k = 0; k < argc; k++) {
		// check if it is successful
		isInt = sscanf(argv[k], "%d", &IntStore);
		if (isInt) {
			IntegerArr[count] = IntStore;
			count++;
		} else {
			// if it is not an integer, store a string using sprintf
			StringArrPtr += sprintf(StringArrPtr, "%s ", argv[k]);
		}
	}

	// print string
	printf("String is: %s\n", StringArr);
	
	for (int j = 0; j < count; j++)
	{
		// print integers
		printf("Integer in order: %d\n", IntegerArr[j]) ;
	}

	return (0) ;
}