#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main()
{
	char *line = NULL;
        size_t len = 1024;
        ssize_t nread = 0;
	char *delimiters = ";|&";
	char *token = NULL;
	char* array[20];
	int i = 0;	
 	/*char *binaryPath = "/bin/ls";*/
  	char *args[] = {"/bin/ls", "-lh", "/home", NULL};

	line = malloc(len * sizeof(char));
	if (!line)
	{
		perror("No allocate");
		exit(-1);
	}

	printf("$ ");
	nread = getline(&line, &len, stdin);
	printf("nred = %ld\n", nread);
	printf("%s\n", line);
	token = strtok(line, delimiters);
	execve(token, args, NULL);
	array[i] = token;
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delimiters);
		array[i] = token;
	}
	array[i] = NULL;
	i = 0;
	printf("----Arguments----\n");
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
        free(line);

	return (0);
       }

