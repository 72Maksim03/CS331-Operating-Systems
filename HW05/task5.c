#include <stdio.h>
#include <stdlib.h>

int main(){
	int max = 0;
	int min = 100;

	int n;

	printf("Enter the number of students: ");
	scanf("%d", &n);

	int *grades = malloc(n*sizeof(int));

	if(grades == NULL){
		printf("\nMemory allocation failed\n");
		return 1;
	}

	printf("Enter the grades: ");

	for (int i = 0; i < n; i++){
		scanf("%d", &grades[i]);

		if(max < grades[i]){
			max = grades[i];
		}
		
		if(min > grades[i]){
			min = grades[i];
		}
	}

	printf("Highest grade: %d\n", max);
	printf("Lowest grade: %d\n", min);

	free(grades);
	return 0;
}
