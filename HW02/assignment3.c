#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main(){
        int ret = fork();

        if (ret == 0){
                execl("/usr/bin/echo", "echo", "Hello from the child process", NULL);
        }

        wait(NULL);
        printf("Parent process done\n");
}
