#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	int ret = fork();

	if (ret == 0){
		printf("Hello from child");
		exit(0);
	} else {
		wait(NULL);
		while(1);
	}
}
