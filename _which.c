#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av)
{
	unsigned int i;
	int j = 0, k = 0;
	struct stat st;
	char *token[20], *env[20];
	char *delim = ":=";
	char *address;
	/*char path[1024] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";*/

	printf("PATH: %s\n", getenv("PATH"));
	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (environ[k])
	{
		env[k] = strtok(environ[k], "=");
		if (strcmp(env[k], "PATH") == 0)
		{
			env[k + 1] = strtok(NULL, "=");
			printf("%s\n", env[k + 1]);
			break;
		}
		k++;
	}
	printf("PATH: %s\n", getenv("PATH"));
	token[j] = strtok(env[k + 1], delim);
	while (token[j])
	{
		j++;
		token[j] = strtok(NULL, delim);
	}
	address = malloc(1024 * sizeof(char));
	if (!address)
	{
		free(address);
		perror("No allocate");
		exit(-1);
	}
	while (av[i])
	{
		j = 0;
		while (token[j])
		{
		
			strcpy(address, token[j]);
			strcat(address, "/");
			strcat(address, av[i]);
			if (stat(address, &st) == 0)
			{
				printf("%s\n", address);
				free(address);
				return (0);
			}
			j++;
		}
		printf(" NOT FOUND\n");
		i++;
	}
	free(address);
	return (0);
}
