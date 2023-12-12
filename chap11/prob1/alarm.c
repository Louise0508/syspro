#include <stdio.h>

int main()
{
	alarm(5);
	printf("loop \n");
	while (1) {
		sleep(1);
		printf("1sec\n");
	}
	printf("error\n");
}

