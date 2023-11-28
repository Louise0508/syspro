#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void print_environment_variable(char *name) {
    char *env_value = getenv(name);
    if (env_value != NULL) {
        printf("%s=%s\n", name, env_value);
    } else {
        printf("Environment variable '%s' not found.\n", name);
    }
}

void print_user_and_group_ids() {
    printf("Real User ID: %d\n", getuid());
    printf("Effective User ID: %d\n", geteuid());
    printf("Real Group ID: %d\n", getgid());
    printf("Effective Group ID: %d\n", getegid());
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [-e ENV_VARIABLE_NAME] [-u] [-g] [-i] [-p]\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'e':
                    if (argc > i + 1) {
                        print_environment_variable(argv[i + 1]);
                        i++;
                    } else {
                        printf("No environment variable name provided.\n");
                    }
                    break;
                case 'u':
                    print_user_and_group_ids();
                    break;
                case 'g':
                    print_user_and_group_ids();
                    break;
                case 'i':
                    printf("Process ID: %d\n", getpid());
                    break;
                case 'p':
                    printf("Parent Process ID: %d\n", getppid());
                    break;
                default:
                    printf("Invalid option: %s\n", argv[i]);
                    break;
            }
        }
    }

    return 0;
}

