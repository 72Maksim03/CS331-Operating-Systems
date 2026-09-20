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
		int *p = NULL;
		*p = 42;
		
		exit(2);
	}

	int statCode1;
	int statCode2;

	waitpid(ret, &statCode1, 0);
	waitpid(ret2, &statCode2, 0);

	if (WIFEXITED(statCode1)){
		printf("Child1 finished with status code %d\n", WEXITSTATUS(statCode1));
	} else {
		printf("Child1 exited with an error\n");
	}

	if (WIFEXITED(statCode2)){
		printf("Child2 finished with status code %d\n", WEXITSTATUS(statCode2));
	} else {
		printf("Child2 exited with an error\n");
	}

}
