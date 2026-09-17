#include <stdio.h>

int main(){
        int arr[] = {1, 2, 3, 4, 5};
        int size = sizeof(arr) / sizeof(arr[0]);

        int *p_arr = arr;

        for (int i = 0; i < size; i++){
                printf("%d\n", *(p_arr + i));
        }

        for (int i = 0; i < size; i++){
                int newVal = *(p_arr + i) * 10;
                *(p_arr + i) = newVal;
        }

        for (int i = 0; i < size; i++){
                printf("Printing %dth value of array, using its name: %d\n", (i+1), arr[i]);
                printf("Printing %dth value of array using pointer: %d\n", (i+1), *(p_arr + i));
        }

        return 0;
}
