all: program1 program2 program3

my_string.o: my_string.c my_string.h
	clang -c my_string.c

program1: program1.c my_string.o my_string.h
	clang program1.c my_string.o -g -o program1

program2: program2.c my_string.o my_string.h
	clang program2.c my_string.o -g -o program2

program3: program3.c
	clang program3.c -g -o program3


clean:
	rm -rf *.o

clobber: clean
	rm -rf program1 program2 program3 program4

