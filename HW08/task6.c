#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char filename[] = "numbers.txt";

	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd == -1){
		printf("Error creating the file\n");
		exit(1);
	}

	char line[8];

	for (int i = 1; i <= 10; i++){
		int len = snprintf(line, sizeof(line), "%d\n", i);

		for (int j = 0; j < len; j++){
			if (write(fd, &line[j], 1) != 1){
				printf("Error writing numbers\n");
				close(fd);
				exit(1);
			}
		}
	}

	close(fd);

	fd = open(filename, O_RDWR);

	if (fd == -1){
		printf("Error opening the file\n");
		exit(1);
	}

	int newlineCount = 0;
	off_t line4Offset = -1;
	char byte;

	while (newlineCount < 3) {
		ssize_t bytesRead = read(fd, &byte, 1);

		if (bytesRead == -1) {
			printf("Error reading the file\n");
			close(fd);
			exit(1);
		}

		if (bytesRead == 0) {
			break;
		}

		if (byte == '\n') {
			newlineCount++;
		}
	}

	if (newlineCount != 3) {
		printf("Could not find the fourth line\n");
		close(fd);
		exit(1);
	}

	line4Offset = lseek(fd, 0, SEEK_CUR);

	if (line4Offset == -1) {
		printf("Error getting line 4 offset\n");
		close(fd);
		exit(1);
	}

	char remainder[256];
    	int remainderLen = 0;

    	while (remainderLen < 256) {
        	ssize_t bytesRead = read(fd, &byte, 1);

        	if (bytesRead == -1) {
            		printf("Error reading the remaining content\n");
            		close(fd);
            		exit(1);
        	}

        	if (bytesRead == 0) {
            		break;
        	}

        	remainder[remainderLen] = byte;
        	remainderLen++;
    	}

	    if (lseek(fd, line4Offset, SEEK_SET) == -1) {
        	printf("Error moving to line 4\n");
        	close(fd);
        	exit(1);
	    }

    	char replacement[] = "100\n";

    	for (int i = 0; i < 4; i++) {
        	if (write(fd, &replacement[i], 1) != 1) {
            		printf("Error writing replacement\n");
            		close(fd);
            		exit(1);
        	}
    	}

    	for (int i = 0; i < remainderLen; i++) {
        	if (write(fd, &remainder[i], 1) != 1) {
            		printf("Error restoring the remaining content\n");
            		close(fd);
            		exit(1);
        	}
    	}


	if (lseek(fd, 0, SEEK_SET) == -1) {
        	printf("Error moving to the beginning of the file\n");
        	close(fd);
        	exit(1);
    	}

    	printf("Final file content:\n");

    	while (1) {
        	ssize_t bytesRead = read(fd, &byte, 1);

        	if (bytesRead == -1) {
            		printf("Error reading final content\n");
            		close(fd);
            		exit(1);
        	}

        	if (bytesRead == 0) {
            		break;
        	}

        	printf("%c", byte);
    	}

	close(fd);

	return 0;
}
