#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char *token = NULL;
	char *delim = ":";
	char *address;
	char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	
	token = strtok(path, delim);

	while (av[i])
	{
		while (token)
		{
			address = strcat(token, av[i]);
			if (stat(address, &st) == 0)
			{
				printf("%s\n", address);
				return (0);
			}
			token = strtok(NULL, delim);
		}
		printf(" NOT FOUND\n");
		i++;
	}
	return (0);
}
