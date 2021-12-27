#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - return the length of a string
 *
 * @s: pointer to string
 * Return: Length of a string
 */

int _strlen(char *s)
{
	int i;

	if (s == NULL)
	{
		return (0);
	}
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
  * _strcmp - comparing two strings
  *
  * @s1: String to compare
  * @s2: String to compare
  *
  * Return: result
  */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * free_grid - free memory space of a grid
 *
 * @grid: 2-dimensional array
 * @height: rows of matrix
 * Return: Nothing
 */

void free_grid(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

extern char **environ;

/**
 * _getenv - funtion that gets an environment variable
 *
 * @name: Name of the environment variable
 * Return: Value of the Variable
 */

char *_getenv(char *name)
{
	int i = 0;
	char *envName = NULL, *value = NULL;

	while (environ[i])
	{
		envName = strtok(environ[i], "=");
		if (_strcmp(envName, NAME) == 0)
		{
			value = strtok(environ[i], NULL);
			return(value);
		}
		i++;
	}
	
}

int main(int ac, char **av)
{
	int i = 0
	/*printf("%s\n", getenv(av[1]));*/
	printf("ac: %d\n", ac);
	printf("%s\n", _getenv(av[1]));
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
