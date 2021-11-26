#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main (void)
{
	char *envp[] = {NULL};
	pid_t pid, pid_p;
	int status, i = 0;
	char *line = NULL;
	char **argv = NULL;
	ssize_t nread = 0;
        size_t len = 0;
	char *promt = "$ ";
 	/*char *binaryPath = "/bin/ls";*/


	line = malloc(len * sizeof(char));
	if (!line)
	{
		perror("No allocate");
		exit(-1);
	}

	printf("Start Shell\n");
	printf("--------------------------\n");
	pid_p = getpid();
	i = 0;
	while (1)
	{

		write(STDOUT_FILENO, promt, 2);
		nread = getline(&line, &len, stdin);
		printf("nread = %ld\n", nread);
		if (strcmp("exit", line) == 0)
		{
			break;
		}
		write(STDOUT_FILENO, line, nread);
		pid = fork();
	
		if (pid == -1)
		{
			printf("Error");
		}
		else if (pid == 0)
		{

			argv[0] = line;
			argv[1] = NULL;
			printf("argv = %s, len = %ld\n", argv[0], strlen(argv[0]));
			printf("before exe: %d\n", getpid());
			sleep(2);
			execve(line, argv, envp);
			printf("Child finish\n");
			printf("----------------\n");
		}
		else 
		{
			printf("Parent: %d - Wait for child_ %d\n", pid_p, pid);
			sleep(2);
			wait(&status);
		}
		i++;
	}
	free(line);

	return (0);
}
