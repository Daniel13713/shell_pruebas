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
	char *argv[2];
	/*char *argv1[] = {"/bin/ls", NULL};*/
	ssize_t nread = 0;
        size_t len = 1024;
	char *promt = "$ ";
	char *delimiter = "\n";
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
	i = 1;
	while (i)
	{

		write(STDOUT_FILENO, promt, 2);
		nread = getline(&line, &len, stdin);

		write(STDOUT_FILENO, line, nread);
		argv[0] = strtok(line, delimiter);
		argv[1] = NULL;
		pid = fork();
	
		printf("pid = %d\n", getpid());
		if (pid == -1)
		{
			printf("Error");
		}
		else if (pid == 0)
		{

			/*printf("argv = %s, line = %s\n", argv[0], line);*/
			if (strcmp(argv[0], "exit") == 0)
			{
				printf("---exit---\n");
				i = 0;
			}
			printf("before exe: %d\n", getpid());
			sleep(2);
			execve(argv[0], argv, envp);
			printf("Child finish\n");
			printf("----------------\n");
		}
		else 
		{
			printf("Parent: %d - Wait for child_ %d\n", pid_p, pid);
			sleep(2);
			wait(&status);
		}
	}
	free(line);

	return (0);
}
