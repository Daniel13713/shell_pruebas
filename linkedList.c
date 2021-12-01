#include "duriv.h"


/**
 * listint_len - print lenthg of listint_t
 *
 * @h: pointer to the first struct
 * Return: length of list_t
 */

unsigned int list_len(const p_list *h)
{
	unsigned int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * *get_node_at_index - return the nth node of linked list
 *
 * @head: pointer to struct
 * @index: position of element of the list
 * Return: Nothing
 */

p_list *get_node_at_index(p_list *head, unsigned int index)
{
	unsigned int i = 0;
	unsigned int len = list_len(head);
	
	if (!head || index >= len)
	{
		return (NULL);
	}
	for (i = 0; i < index; i++)
	{
		head = head->next;
	}
	return (head);
}

/**
 * free_list - free all list
 *
 * @head: pointer to struct
 * Return: Nothing
 */

void free_list(p_list **head)
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
		free(next_free->name);
		free(next_free->value);
		free(next_free);
	}
	*head = NULL;
}

/**
 * add_node_end - add a new node to the end
 *
 * @head: pointer to pointer of structure
 * @n: integer
 * Return: pointer to structure (pointer) or null if fail
 */

p_list *add_node_end(p_list **head, char const *name, char const *value)
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
	if (!name)
	{
		new->name = NULL;
	}
	else
	{
		new->name = strdup(name);
	}
	if (!value)
	{
		new->value = NULL;
	}
	else
	{
		new->value = strdup(value);
	}
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
