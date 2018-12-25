int main() {
	char arr[14] = {'I',' ','L','O','V','E',' ','C','I','T','5','9','3','\0'} ;
	
	int *arr_ptr = 0 ; //pointer declaration
	
	arr_ptr = &arr;
	
	lc4_puts (arr) ;

	return (0) ;
}