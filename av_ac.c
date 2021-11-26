#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(__attribute__((__unused__)) int ac, char **av)
{
	while (*av)
	{
		printf("[I'am in av_ac program]: %s\n",*av);
		av++;
	}
	return (0);
}
