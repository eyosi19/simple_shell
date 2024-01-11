#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

int main(void)
{
	pid_t pid;
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\nExiting Shell.\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, (char *)NULL) == -1)
			{
				fprintf(stderr, "simple_shell: command not found: %s\n", command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);

			if (!WIFEXITED(status))
			{
				fprintf(stderr, "simple_shell: error executing command: %s\n", command);
			}
		}
	}
	return (0);
}
