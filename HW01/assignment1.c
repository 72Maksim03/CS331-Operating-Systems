#include <stdio.h>

int main(){
        int x = 5;

        int *p_x = &x;

        printf("Address of the variable: %p\n", &x);
        printf("Address of the variable using pointer: %p\n", p_x);

        *p_x = 10;

        printf("New value of x: %d\n", x);

        return 0;
}
