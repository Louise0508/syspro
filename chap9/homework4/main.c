#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command) {
	int background = 0;
	
	if (command[strlen(command) - 1] == '&') {
		background = 1;
		command[strlen(command) - 1] = '\0';
	}

	pid_t pid = fork();

	if (pid == 0) {
		char *args[MAX_COMMAND_LENGTH / 2];
		args[0] = strtok(command, " ");
		int i = 1;

		while ((args[i] = strtok(NULL, " ")) != NULL) {
			i++;
		}

		if (background) {
			args[i++] = "&";
		}
		
		args[i] = NULL;

		execvp(args[0], args);	

		fprintf(stderr, "fail\n");

		exit(EXIT_FAILURE);

  	} else if (pid < 0) {
		fprintf(stderr, "process fail\n");
		exit(EXIT_FAILURE);
   	} else {
		if (!background) {
			int status;
			waitpid(pid, &status, 0);
		}
   	}
}

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("[Shell] ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0) {
			break;
		}

		execute_command(command);
	}
	
	return 0;
}

