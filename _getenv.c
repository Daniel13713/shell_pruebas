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
	int k = 0;
	char *env[1024];


	while (environ[k])
	{
		env[k] = strtok(environ[k], "=");
		if (strcmp(env[k], name) == 0)
		{	
			env[k + 1] = strtok(NULL, "=");
			return (env[k + 1]);
		}
		k++;
	}
	return (NULL);

}

int main(int ac, char **av)
{
	printf("color: %s\n", getenv("LS_COLORS"));
	printf("ac: %d\n", ac); 
	printf("%s\n", _getenv(av[1]));
	return (0);
}

