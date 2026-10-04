#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr = malloc(10*sizeof(int));

	if(arr == NULL){
		printf("Memory allocation failed\n");
		return 1;
	}
	printf("Enter 10 integers: ");

	for(int i =0;i<10;i++){
		scanf("%d", &arr[i]);
	}

	int *new_arr = realloc(arr, (5*sizeof(int)));

	if(new_arr == NULL){
		printf("Memory reallocation failed\n");
		return 1;
	}

	printf("Array after resizing:");
	for (int i = 0; i < 5; i++){
		printf(" %d", new_arr[i]);
	}
	
	printf("\n");
	free(new_arr);
	return 0;
}
