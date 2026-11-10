#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char source[256];
	char dest[256];

	printf("Enter the source file path: ");
	scanf("%255s", source);

	printf("Enter the destination file path: ");
	scanf("%255s", dest);

	int sDesc = open(source, O_RDONLY);
	if(sDesc == -1){
		printf("Error opening %s file\n", source);
		exit(1);
	}

	int dDesc = open(dest, O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(dDesc == -1){
		printf("Error opening %s file\n", dest);
		close(sDesc);
		exit(1);
	}

	char byte;
	ssize_t bytesRead;
	long totalBytes = 0;

	while((bytesRead = read(sDesc, &byte, 1))>0){
		if(write(dDesc, &byte, 1) == -1){
			printf("Error writing to destination file\n");
			close(sDesc);
			close(dDesc);
			exit(1);
		}
		totalBytes++;
	}

	if(bytesRead == -1){
		printf("Error reading the source file\n");
		close(sDesc);
		close(dDesc);
		exit(1);
	}

	printf("Total bytes copied %ld\n", totalBytes);

	close(sDesc);
	close(dDesc);
}
