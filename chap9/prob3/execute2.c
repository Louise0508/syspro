#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("P process start\n");
	if (fork() == 0) {
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "fisrt false");
		exit(1);
	}

	if (fork() == 0) {
		execl("/bin/date", "date", NULL);
		fprintf(stderr, "second false");
		exit(2);
	}
	
	if (fork() == 0) {
		execl("/bin/ls", "ls", "-l", NULL);
		fprintf(stderr, "3 false");
		exit(3);
	}

	printf("P process end\n");
}
