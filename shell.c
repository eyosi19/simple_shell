#include "main.h"

void display_prompt(void)
{
	printf("simple_shell> ");
}

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(command, command, (char *) NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

int main (void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		
		if (gets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		execute_command(command);
	}

	return (0);
}
