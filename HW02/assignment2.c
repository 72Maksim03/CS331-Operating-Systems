#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main(){
	int ret1 = fork();
	if (ret1 == 0){
		execl("/usr/bin/ls", "ls", NULL);
	}
	wait(NULL);
	int ret2 = fork();
	if (ret2 == 0){
		execl("/usr/bin/date", "date", NULL);
	}
	wait(NULL);
	printf("Parent process done\n");
}
