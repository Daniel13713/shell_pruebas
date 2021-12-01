#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	/*char path[] = "/bin/cat";*/
	/*char path[] = "./fork.out";*/
	char path[] = "/bin/ls";
	char *argv[] = {"ls", "-l", NULL};
	char *envp[] = {NULL};
	pid_t pid, pid_p;
	int status, i = 0;

	printf("Start Shell\n");
	printf("--------------------------\n");
	pid_p = getpid();
	i = 0;
	while (i < 1)
	{
		pid = fork();
	
		if (pid == -1)
		{
			printf("Error");
		}
		else if (pid == 0)
		{
			printf("before exe: %d\n", getpid());
			sleep(2);
			execve(path, argv, envp);
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
	
	return 0;
}
