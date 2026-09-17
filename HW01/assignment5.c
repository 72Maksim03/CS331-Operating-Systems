#include <stdio.h>

int main(){
        char str[] = "Hello";

        char *pointer = str;
        int size = 0;

        while(*pointer != '\0'){
                printf("%c", *pointer);
                size++;
                pointer++;
        }

        printf("\nThe size of the string: %d", size);
}
