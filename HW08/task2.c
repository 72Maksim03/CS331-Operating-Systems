#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char filename[8] = "data.txt";

	int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd == -1){
		printf("Error opening/creating the file\n");
		exit(1);
	}

	ssize_t bytesWritten = write(fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	if (bytesWritten == -1){
		printf("Failed to write to the file\n");
		close(fd);
		exit(1);
	}

	close(fd);

	fd = open(filename, O_RDWR);

	off_t sz = lseek(fd, 0, SEEK_END);
	if(sz == -1){
		printf("Error getting the file size");
		close(fd);
		exit(1);
	}
	printf("Current file size: %ld bytes\n", (long)sz);

	int status = ftruncate(fd, 10);
	if (status == -1){
		printf("Failed to truncate the file\n");
		close(fd);
		exit(1);
	}

	sz = lseek(fd, 0, SEEK_END);
	if(sz == -1){
		printf("Error getting file new size");
		close(fd);
		exit(1);
	}
	printf("New size: %ld bytes\n", (long)sz);

	lseek(fd, 0, SEEK_SET);

	char buffer[(int)sz+1];
	
	ssize_t bytesRead = read(fd, buffer, (int)sz);
	if(bytesRead == -1){
		printf("Error reading the file");
		close(fd);
		exit(1);
	}

	buffer[bytesRead]='\0';

	printf("Remaining content: %s\n", buffer);

	close(fd);
}
