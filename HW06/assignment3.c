#include <stdio.h>

struct Struct1{
	char a;
	int b;
	double c;
};

#pragma pack(1)
struct Struct2{
	char a;
	int b;
	double c;
};

int main(){
	struct Struct1 str1;
        printf("Struct without pragma pack\n");
        printf("The size of struct: %zu\n", sizeof(str1));
        printf("The memory address of char: %p\n", &str1.a);
        printf("The memory address of int: %p\n", &str1.b);
        printf("The memory address of double: %p\n", &str1.c);

	struct Struct2 str2;
        printf("Struct with pragma pack(1)\n");
        printf("The size of struct: %zu\n", sizeof(str2));
        printf("The memory address of char: %p\n", &str2.a);
        printf("The memory address of int: %p\n", &str2.b);
        printf("The memory address of double: %p\n", &str2.c);
}
