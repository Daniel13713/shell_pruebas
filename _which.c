#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	unsigned int i;
	int j = 0;
	struct stat st;
	char *token[20];
	char *delim = ":";
	char *address = NULL;
	char path[1024] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;

	printf("path: %s\n", path);
	token[j] = strtok(path, delim);
	while (token[j])
	{
		printf("tokenw: %s\n", token[j]);
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
		
			printf("In while\n");
			token[j] = strcat(token[j], "/");
			address = strcat(token[j], av[i]);
			printf("address: %s\n", address);
			if (stat(address, &st) == 0)
			{
				printf("%s\n", address);
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
