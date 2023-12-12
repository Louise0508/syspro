#include <stdio.h>
#include <signal.h>

void alarmHandler();

int main()
{
	signal(SIGALRM, alarmHandler);
	alarm(5);
	printf("loop\n");
	while (1) {
		sleep(1);
		printf("1sec\n");
	}
	printf("error\n");
}

void alarmHandler(int signo)
{
	printf("wake up\n");
	exit(0);
}
