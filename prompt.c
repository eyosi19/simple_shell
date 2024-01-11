#include "main.h"

/**
 * read_line - reads the command line
 * Return: line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t size = 0;
	int ret = 0;

	printf("simple_shell$ ");

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		exit(-1);
	}
	ret = strlen(line);
	line[ret - 1] = '\0';

	return (line);
}
