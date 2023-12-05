#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *command) {
	char *args[MAX_ARGUMENTS];
	int i = 0;

	char *token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGUMENTS - 1) {
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	
	args[i] = NULL;

	pid_t pid = fork();

	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("Error");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("Fork failed");
	} else {
		int status;
		waitpid(pid, &status, 0);
	}
}

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("[shell] ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0) {
			break;
		}

		if (strstr(command, "&")) {
			command[strcspn(command, "&")] = '\0';
			pid_t pid = fork();

			if (pid == 0) {
				execute_command(command);
				exit(EXIT_SUCCESS);
			}
		} else {
			execute_command(command);
		}
	}
	
	return 0;
}
