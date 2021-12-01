#include "duriv.h"
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int _unsetenv(const char *name)
{

	int k = 0;
	char *env[1024];
	char *nameCopy = NULL;
	char *value = "\n";


	nameCopy = malloc(1024 * sizeof(char));
	if (!nameCopy)
	{
		free(nameCopy);
		perror("No allocate");
		exit(-1);
	}
	/*environCopy = malloc(100 * sizeof(char*));
	if (!environCopy)
	{
		free(environCopy);
		perror("No allocate");
		exit(-1);
	}*/

	while (environ[k])
	{
		env[k] = strtok(environ[k], "=");
		if (strcmp(env[k], name) == 0)
		{
			env[k + 1] = value;
			k--;
			break;
		}
		env[k + 1] = strtok(NULL, "\n");
		k++;
	}
	k++;

	strcpy(environ[k], env[k]);
	strcat(environ[k], "=");
	strcat(environ[k], env[k + 1]);
	free(nameCopy);
	return (0);
}

/**
 * main - Create a linked list of enviroments vaiables
 *
 * Return: 0 on Success
 */
int main(int ac, char **av)
{
	int k = 0;

	if (ac != 2)
	{
		printf("try ./exe NAME\n");
		return (-1);
	}
	if (!av[1])
	{
		printf("Error, NAME can't null\n");
		return (-1);
	}
	/*printf("setenv: %d", setenv(av[1], av[2], atoi(av[3])));*/
	_unsetenv(av[1]);
	while (environ[k])
	{
		printf("%s\n", environ[k]);
		k++;
	}
	/*free_p_list(&head);*/
	return (0);
}
