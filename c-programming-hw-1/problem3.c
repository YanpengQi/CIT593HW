int main() {
	char c = '';  // use to store char from keyboard
	char enter=  0x0A;  // store ascii code of enter
	
	while (c != enter) {
		lc4_getc(c);
		lc4_putc(c);
	}
	return (0);
	
}