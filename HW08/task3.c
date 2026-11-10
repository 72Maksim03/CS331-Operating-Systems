#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char filename[256];
	
	printf("Enter the file path: ");
	scanf("%255s", filename);

	int fd = open(filename, O_RDONLY);

	if (fd == -1){
		printf("Error opening the file\n");
		exit(1);
	}

	off_t size = lseek(fd, 0, SEEK_END);

	if(size == -1){
		printf("Error getting the file size\n");
		close(fd);
		exit(1);
	}

	if (size == 0){
		printf("\n");
	} else {
		char byte;

		for (off_t i = size - 1; i>=0; i--){
			off_t p = lseek(fd, i, SEEK_SET);

			if (p == -1){
				printf("Error moving file position\n");
				close(fd);
				exit(1);
			}

			ssize_t byteRead = read(fd, &byte, 1);
			if(byteRead == -1){
				printf("Error reading the file\n");
				close(fd);
				exit(1);
			}

			printf("%c", byte);
		}
		printf("\n");
	}

	close(fd);
}
