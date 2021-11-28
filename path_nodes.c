#include "duriv.h"

typedef struct p_list
{
	char *data;
	struct p_list *next;
} p_list;


int main(void)
{
	char *p_dirs;
	char *dirs = NULL;
	p_list *head;
	p_list *new;
	
	head = (p_list*)dirs;
	new = malloc(sizeof(p_list));
	if (new == NULL)
	{
		printf("Malloc failed");
		return (1);
	}
	p_dirs = getenv("PATH");
	dirs = strtok(p_dirs, ":");
	
	new->data = dirs;
	new->next = head;
	head = new;
	while (dirs)
	{
		printf("%s\n", dirs);
		dirs = strtok(NULL, ":");
	}
	return (0);
}
