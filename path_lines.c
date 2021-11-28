#include "duriv.h"

int main(void)
{
	char *p_dirs;
	char *dirs;

	p_dirs = getenv("PATH");
	dirs = strtok(p_dirs, ":");
	while (dirs)
	{
		printf("%s\n", dirs);
		dirs = strtok(NULL, ":");
	}
	return (0);
}
