#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;
void alarmHandler();

int main(int argc, char *argv[])
{
	int child, status, limit;

	signal(SIGALRM, alarmHandler);
	sscanf(argv[1], "%d", &limit);
	alarm(limit);

	pid = fork();
	
	if (pid == 0) {
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s:error\n", argv[1]);
	} else {
		child = wait(&status);
		printf("[%d] C process %d stop \n", getpid(), pid);
	}
}

void alarmHandler()
{
	printf("[alarm] C process %d error\n", pid);
	kill(pid, SIGINT);
}
