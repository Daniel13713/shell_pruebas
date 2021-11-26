#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	pid_t child_pid1;
	pid_t child_pid2;
	pid_t child_pid3;
	int status;

    printf("0 -- %d\n", getpid());

    child_pid1 = fork();
    printf("1 -- current = %d -- child? = %d\n", getpid(), child_pid1);
    if (child_pid1 == 0)
    {
        printf("1 -- Wait for me, wait for me: %d\n", getpid());
        sleep(3);
    }
    else
    {
	wait(&status);
        printf("Oh, it's all better now (i'm %d)\n", getpid());
    }

    child_pid2 = fork();
    printf("2 -- current = %d -- child? = %d\n", getpid(), child_pid2);
    if (child_pid2 == 0)
    {
        printf("2 -- Wait for me, wait for me: %d\n", getpid());
        sleep(3);
    }
    else
    {
	wait(&status);
        printf("Oh, it's all better now (i'm %d)\n", getpid());
    }

    child_pid3 = fork();
    printf("3 -- current = %d -- child? = %d\n", getpid(), child_pid3);
    if (child_pid3 == 0)
    {
        printf("3 -- Wait for me, wait for me: %d\n", getpid());
        sleep(3);
    }
    else
    {
	wait(&status);
        printf("Oh, it's all better now (i'm %d)\n", getpid());
    }

    printf("Hello %d\n", getpid());
    return 0;
}
