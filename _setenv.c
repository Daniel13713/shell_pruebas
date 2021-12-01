#include "duriv.h"
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{

	/*char *nameCopy = NULL, *valueCopy = NULL;
	char *valueEnv = NULL;*/
	p_list *head, *temp;
	char *envName = NULL, *envValue = NULL;
	int k = 0;
	
	head = NULL;
	while (environ[k])
	{
		envName = strtok(environ[k], "=");
		envValue = strtok(NULL, "\n");
		temp = add_node_end(&head, envName, envValue);
		printf("%s=%s\n", envName, envValue);
		printf("-> %s=%s\n", temp->name, temp->value);
		k++;
	}
	if (overwrite != 0)
	{
		printf("Editar variable %s=%s\n", name, value);
	}

	/*
	valueEnv = malloc(1024 * sizeof(char));
	if (!valueEnv)
	{
		free(valueEnv);
		perror("No allocate");
		exit(-1);
	}

	valueEnv = _getenv(name);

	if(valueEnv == NULL)
	{
		printf("(NO EXISTE)->Añadir %s=%s\n", name, value);
		printf("here\n");
		temp = add_node_end(&head, name, value);
		printf("here1\n");
		printf("Añadida-> %s=%s\n", temp->name, temp->value);
		printf("here2\n");
	}
	else
	{
		printf("(existe)->EditarA %s=%s\n", name, value);

	}
	if (overwrite != 0)
	{
		printf("Editar variable %s=%s\n", name, value);
	}


		if (strcmp(env[k], name) == 0)
		{
			k--;
			break;
		}
		k++;
	}

			k++;
	nameCopy = malloc(1024 * sizeof(char));
	if (!nameCopy)
	{
		free(nameCopy);
		perror("No allocate");
		exit(-1);
	}
	valueCopy = malloc(1024 * sizeof(char));
	if (!valueCopy)
	{
		free(valueCopy);
		perror("No allocate");
		exit(-1);
	}
	strcpy(nameCopy, name);
	strcpy(valueCopy, value);
	strcat(nameCopy, "=");
	strcat(nameCopy,valueCopy);
	environ[k] = nameCopy;

	if (overwrite != 0)
	{
		printf("Editar variable %s=%s\n", name, value);
	}
	free(nameCopy);
	free(valueCopy);
	free(valueEnv);*/
	free_list(&head);
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

	if (ac != 4)
	{
		printf("try ./exe NAME VALUE NUM\n");
		return (-1);
	}
	if (!av[1])
	{
		printf("Error, name can't null\n");
		return (-1);
	}
	/*printf("setenv: %d", setenv(av[1], av[2], atoi(av[3])));*/
	_setenv(av[1], av[2], atoi(av[3]));
	while (environ[k])
	{
		printf("%s\n", environ[k]);
		k++;
	}
	return (0);
}
