#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

char *_which(char **command)
{
	unsigned int i;
	int j = 0, k = 0;
	struct stat st;
	char *token[1024], *env[1024];
	char *address;
	/*char path[1024] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";*/

	i = 1;
	while (environ[k])
	{
		env[k] = strtok(environ[k], "=");
		if (strcmp(env[k], "PATH") == 0)
		{
			env[k + 1] = strtok(NULL, "\n");
			break;
		}
		k++;
	}
	token[j] = strtok(env[k + 1], ":");
	while (token[j])
	{
		j++;
		token[j] = strtok(NULL, ":");
	}
	address = malloc(1024 * sizeof(char));
	if (!address)
	{
		free(address);
		perror("No allocate");
		exit(-1);
	}
	while (command[i])
	{
		j = 0;
		while (token[j])
		{
		
			strcpy(address, token[j]);
			strcat(address, "/");
			strcat(address, command[i]);
			if (stat(address, &st) == 0)
			{
				return (address);
			}
			j++;
		}
		printf(" NOT FOUND\n");
		i++;
	}
	free(address);
	return (NULL);
}
int main(int ac, char *argv[])
{
	char *path = NULL;
	printf("ac = %d\n", ac);
	path = _which(argv);
	if (path)
	{
		printf("%s\n", path);
		free(path);
	}
	return (0);
}
