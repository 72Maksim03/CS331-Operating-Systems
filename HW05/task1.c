#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int sum = 0;

	printf("Enter the number of elements: ");

	scanf("%d", &n);

	int *arr = malloc(n * sizeof(int));

	if (arr == NULL){
		printf("Memory allocation failed\n");
		return 1;
	}

	printf("Enter 5 integers: ");

	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	free(arr);
	
	printf("Sum of the array: %d\n", sum); 
	return 0;
}
