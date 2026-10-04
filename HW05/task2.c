#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int sum = 0;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int* arr = calloc(n, sizeof(int));
	printf("Array after calloc:");

	if(arr==NULL){
		printf("Memory allocation failed");
		return 1;
	}

	for(int i=0;i<n;i++){
		printf(" %d", arr[i]);
	}

	printf("\nEnter 4 integers: ");

	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	printf("Updated array:");
	for(int i=0;i<n;i++){
		printf(" %d", arr[i]);
	}

	free(arr);
	printf("\nAverage of the array: %f\n", (double)sum/n);
}
