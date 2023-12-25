#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	execlp(
			"betty",
			"betty",
			"betty.c",
			NULL
		  );
}
