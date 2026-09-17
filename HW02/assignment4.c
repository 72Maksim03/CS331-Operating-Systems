#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main(){
	int ret = fork();

	if (ret == 0){
		execl("/usr/bin/grep", "grep", "-in", "main", "test.txt", NULL);
	}
	wait(NULL);
	printf("Parent process completed\n");
}
