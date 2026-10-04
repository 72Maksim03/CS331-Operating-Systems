#include <stdio.h>
#include <stdlib.h>

int main(){
	char **strings = malloc(3*sizeof(char *));

	if (strings == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	for (int i = 0; i < 3; i++){
		strings[i] = malloc(50*sizeof(char));

		if(strings[i] == NULL){
			printf("Memory allocation failed\n");

			for (int j = 0; j < i; j++){
				free(strings[j]);
			}

			free(strings);
			return 1;
		}
	}

	printf("Enter 3 strings: ");

	for(int i = 0; i < 3; i++){
		scanf("%50s", strings[i]);
	}

	char **new_strings = realloc(strings, 5*sizeof(char *));

	if(new_strings == NULL){
		printf("Memory allocation failed\n");
		
		for(int i = 0; i< 3; i++){
			free(strings[i]);
		}

		free(strings);
		return 1;
	}

	for (int i = 3; i < 5; i++){
		new_strings[i] = malloc(50*sizeof(char));
		
		if (new_strings[i] == NULL) {
			printf("Memory allocation failed\n");

        		for (int j = 0; j < i; j++) {
            			free(new_strings[j]);
        		}

        		free(new_strings);
  			return 1;
		}


	}

	printf("Enter 2 more strings: ");

	for(int i = 3; i < 5; i++){
		scanf("%50s", new_strings[i]);
	}

	printf("All strings:");

	for(int i = 0; i < 5; i++){
		printf(" %50s", new_strings[i]);
	}
	printf("\n");

	for (int i = 0; i < 5; i++){
		free(new_strings[i]);
	}

	free(new_strings);

	return 0;
}
