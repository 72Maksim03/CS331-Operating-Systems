#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char filename[] = "log.txt";

	int fd = open(filename, O_WRONLY|O_CREAT|O_APPEND, 0644);

	if(fd == -1){
		printf("Error opening/creating the file\n");
		exit(1);
	}

	char line[256];
	int i = 0;
	char byte;

	while (i < 255) {
		ssize_t bytesRead = read(0, &byte, 1);

		if (bytesRead == -1) {
			printf("Error reading input\n");
        		close(fd);
			exit(1);
    		}

    		if (bytesRead == 0 || byte == '\n') {
        		break;
    		}

    		line[i] = byte;
    		i++;
	}

	line[i] = '\0';

	char output[320];
	int len = snprintf(output, sizeof(output), "PID=%d: %.*s", getpid(), i, line);

	if(len < 0 || len >= sizeof(output)){
		printf("Error formatting log entry\n");
		close(fd);
		exit(1);
	}

	if(len == 0 || output[len-1] != '\n'){
		output[len]='\n';
		len++;
	}

	for(int k=0; k<len; k++){
		ssize_t bytesWritten = write(fd, &output[k], 1);

		if(bytesWritten == -1){
			printf("Error writing to the log file\n");
			close(fd);
			exit(1);
		}
	}

	off_t p = lseek(fd, 0, SEEK_CUR);
	if (p == -1){
		printf("Error getting final file position");
		close(fd);
		exit(1);
	}

	printf("Final file offset: %ld\n", (long)p);

	close(fd);
}

// O_APPEND makes each write operation start at the end of the file. After writing, the file offset increases by the number of bytes written. So, lseek(fd, 0, SEEK_CUR) returns the updated file offset
