#include <stdio.h>
#include <stdlib.h>

void func1(){
	printf("Cleanup function1\n");
}

void func2(){
	printf("Cleanup function2\n");
}

int main(){
	atexit(func1);
	atexit(func2);


	int a = 5;
	int b = 10;
	int c = a + b;
	printf("Hello, world!\n");
	
	exit(0);
}
