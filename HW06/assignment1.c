#include <stdio.h>

int main(){
	int a;
	char b;
	double c;
	short d;

	printf("Size of int: %zu\n", sizeof(a));
	printf("Size of char: %zu\n", sizeof(b));
	printf("Size of double: %zu\n", sizeof(c));
	printf("Size of short: %zu\n", sizeof(d));
	
	printf("Address of int a: %p\n", &a);
	printf("Address of char: %p\n", &b);
	printf("Address of double: %p\n", &c);
	printf("Address of short: %p\n", &d);
	
}
