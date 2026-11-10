#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char filename[] = "sparse.bin";

	int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0644);

	if(fd == -1){
		printf("Error opening/creating the file\n");
		exit(1);
	}

	ssize_t bytesWritten = write(fd, "START", 5);

	if (bytesWritten == -1){
		printf("Error writing to file\n");
		close(fd);
		exit(1);
	}

	off_t p = lseek(fd, 1024*1024, SEEK_CUR);

	if(p == -1){
		printf("Error changing the position\n");
		close(fd);
		exit(1);
	}

	bytesWritten = write(fd, "END", 3);

	if (bytesWritten == -1){
		printf("Error writing to file\n");
		close(fd);
		exit(1);
	}

	close(fd);

	int fd2 = open(filename, O_RDONLY);

	off_t p2 = lseek(fd2, 0, SEEK_END);

	printf("File size is: %ld\n", (long)p2);
}

/*
 * The skipped area in the file is a hole in sparse file, and the filesystem does not allocate physical disk blocks for this unwritten area
 */
