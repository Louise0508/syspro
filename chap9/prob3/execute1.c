#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("P process start\n");
	if (fork() == 0) {
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "first false");
		exit(1);
	}

	printf("P process end\n");
}
