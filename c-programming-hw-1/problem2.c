/********************************************************
 * file name   : problem2.c                             *
 * author      : Thomas Farmer
 * description : C program to call LC4-Assembly TRAP_PUTC
 *               the TRAP is called through the wrapper 
 *               lc4putc() (located in lc4_stdio.asm)   *
 ********************************************************
*
*/

int main() {

	char c = 'A' ;		/* ASCII A = x41 in hex, #65 in dec. */

	lc4_putc (c) ;

	return (0) ;

}
