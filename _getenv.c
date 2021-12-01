#include "duriv.h"
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - funtion that gets an environment variable
 *
 * @name: Name of the environment variable
 * Return: Value of the Variable
 */

char *_getenv(const char *name)
{
	p_list *head, *temp;
	char *envName = NULL, *envValue = NULL, *get = NULL;
	int k = 0, n = -1;
	
	head = NULL;
	while (environ[k])
	{
		envName = strtok(environ[k], "=");
		envValue = strtok(NULL, "\n");
		temp = add_node_end(&head, envName, envValue);
		if (temp != NULL)
		{
			if (strcmp(temp->name, name) == 0 && temp->value)
			{	
				n = k;
				get = strdup(temp->value);
			}
		}
		k++;
	}
	free_list(&head);
	if (n != -1)
	{
		return (get);
	}
	/*
	int k = 0;
	char *env[1024];


	while (environ[k])
	{
		env[k] = strtok(environ[k], "=");
		if (strcmp(env[k], name) == 0)
		{	
			env[k + 1] = strtok(NULL, "\n");
			return (env[k + 1]);
		}
		k++;
	}*/
	return (NULL);

}

int main(int ac, char **av)
{
	char *result;
	/*printf("%s\n", getenv(av[1]));*/
	printf("ac: %d\n", ac);
	result = _getenv(av[1]);
	if (result)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("NULL\n");
	}
	free(result);
	return (0);
}

