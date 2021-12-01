#include "duriv.h"


char *_getenv(const char *name);
/**
 * free_p_list - free all list
 *
 * @head: pointer to struct
 * Return: Nothing
 */

void free_p_list(p_list **head)
{
	p_list *current = NULL;
	p_list *next_free = NULL;

	if (head == NULL)
	{
		return;
	}
	current = *head;
	while (current)
	{
		next_free = current;
		current = current->next;
		free(next_free->data);
		free(next_free);
	}
	*head = NULL;
}

/**
 * add_nodeint_end - add a new node to the end
 *
 * @head: pointer to pointer of structure
 * @n: integer
 * Return: pointer to structure (pointer) or null if fail
 */

p_list *add_nodeint_end(p_list **head, const char *str)
{
	p_list *new = NULL;
	p_list *last = NULL;


	new = malloc(sizeof(p_list));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	new->data = strdup(str);

	if (!*head)
	{
		*head = new;
	}
	else
	{
		last = *head;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new;
	}
	return (new);
}

/**
 * main - Create a linked list of PATH directories
 *
 * Return: 0 on Success
 */
int main(void)
{
	char *p_dirs;
	char *dirs = NULL;
	p_list *head;
	p_list *temp;

	head = NULL;
	p_dirs = _getenv("PATH");
	dirs = strtok(p_dirs, ":");
	
	temp = add_nodeint_end(&head, dirs);
	while (dirs)
	{
		printf("%s\n", dirs);
		printf("dirs_list: %s\n", temp->data);
		dirs = strtok(NULL, ":");
		if (dirs == NULL)
		{
			free_p_list(&head);
			break;
		}
		temp->next = add_nodeint_end(&head, dirs);
		temp = temp->next;

	}
	return (0);
}
