#include <stdio.h>
#include <unistd.h>

int main(){
	int ret = fork();
	int procID = getpid();

	if (ret == 0){
		printf("Child process id: %d\n", procID);
	} else {
		printf("Parent process id: %d\n", procID);
	}
}
