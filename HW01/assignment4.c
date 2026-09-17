#include <stdio.h>

int main(){
        int num = 10;

        int *p_num = &num;
        int **pp_num = &p_num;

        printf("Printing using pointer: %d\n", *p_num);
        printf("Printing using double-pointer: %d\n", **pp_num);

        return 0;
}
