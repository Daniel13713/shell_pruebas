#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
	pid_t pid1;
	pid_t pid2;
    pid1 = fork();
  	printf("1 --(i'am: %d) i return = %d\n", getpid(), pid1);
    pid2 = fork();
  	printf("2 --(i'am: %d) i return = %d\n", getpid(), pid2);
    printf("Hello world! (i'am: %d)\n", getpid());
    return 0;
}
