#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
        int ret1 = fork(); //child1
        if (ret1 == 0){
                int ret2 = fork(); //child2
                if (ret2 == 0){
                        fork(); //child3
                }
        } else {
                fork(); //child4
        }

	while(1);

        return 0;
}
