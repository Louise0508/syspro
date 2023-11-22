#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid, child, status;
    printf("[%d] P process start \n", getpid());
    pid = fork();
    if (pid == 0) {
        printf("[%d] I process start \n", getpid());
        exit(1);
    }
    child = wait(&status);
    printf("[%d] I process %d end \n", getpid(), child);
    printf("\t end code %d\n", status>>8);
}

