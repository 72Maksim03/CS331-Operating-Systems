#include <stdio.h>

struct Struct1{
	char a;
	int b;
	double c;
};
struct Struct2{
	int a;
	double b;
	char c;
};
struct Struct3{
	double a;
	int b;
	char c;
};

int main(){
	struct Struct1 str1;
	printf("Struct with char, int, double ordering\n");
	printf("The size of struct: %zu\n", sizeof(str1));
	printf("The memory address of char: %p\n", &str1.a);
	printf("The memory address of int: %p\n", &str1.b);
	printf("The memory address of double: %p\n", &str1.c);

	struct Struct2 str2;
	printf("Struct with int, double, char ordering\n");
        printf("The size of struct: %zu\n", sizeof(str2));
        printf("The memory address of int: %p\n", &str2.a);
        printf("The memory address of double: %p\n", &str2.b);
        printf("The memory address of char: %p\n", &str2.c);

	struct Struct3 str3;
	printf("Struct with double, int, char ordering\n");
        printf("The size of struct: %zu\n", sizeof(str3));
        printf("The memory address of double: %p\n", &str3.a);
        printf("The memory address of int: %p\n", &str3.b);
        printf("The memory address of char: %p\n", &str3.c);
}
