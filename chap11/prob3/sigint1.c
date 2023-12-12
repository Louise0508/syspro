#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void intHandler();

int main()
{
	signal(SIGINT,intHandler);
	while (1)
		pause();
	printf("error\n");
}

void intHandler(int signo)
{
	printf("IT Signal\n");
	printf("signal num: %d\n", signo);
	exit(0);
}

