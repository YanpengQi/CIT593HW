all: assembler

assembler: assembler.c asm_parser.o asm_parser.h
	clang assembler.c asm_parser.o -g -o assembler

asm_parser.o: 	asm_parser.c 
	clang -c asm_parser.c


clean:
	rm -rf *.o

clobber: clean
	rm -rf assembler test1.obj