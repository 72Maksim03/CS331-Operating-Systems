#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int ret = fork();
	
	if (ret == 0){
		printf("Hello from child 1\n");
		exit(4);
	}
	int ret2 = fork();
	if(ret2 == 0){
		printf("Hello from child2\n");
		exit(2);
	}

	int statCode1;
	int statCode2;

	waitpid(ret2, &statCode2, 0);
	wait(&statCode1);

	printf("Child1 finished with status code %d\n", WEXITSTATUS(statCode1));
	printf("Child2 finished with status code %d\n", WEXITSTATUS(statCode2));

}
