#########################################################
#  file name   : Makefile                               #
#  author      : Thomas Farmer                          #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
#
#

all: program1 program2 program3 program4a program4b program5

program1: program1.c
	clang program1.c -o program1

program2: program2.c
	clang program2.c -o program2

program3: program3.c
	clang program3.c -o program3

program4a: program4a.c
	clang program4a.c -o program4a

program4b: program4b.c
	clang program4b.c -o program4b

program4: program4a program4b

program5_swap.o: program5_swap.c program5_swap.h
	clang -c program5_swap.c 

program5.o: program5.c
	clang -c program5.c

program5: program5.o program5_swap.o
	clang program5_swap.o program5.o -o program5
	
program6: program6.o program5_swap.o
	clang program5_swap.c program6.c -o program6

program6: program7.c
	clang program7.c -o program7

clean:
	rm -rf *.o

clobber: clean
	rm -rf program1 program2 program3 problabm4a program4b program5

