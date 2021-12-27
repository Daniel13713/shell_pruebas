#ifndef _DURIV_H_
#define _DURIV_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* struct */
typedef struct p_list
{
	char *name;
	char *value;
	struct p_list *next;
} p_list;

/* Mandatory Prototypes */
char *_getenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* Linked list functions */
p_list *add_node_end(p_list **head, char const *name, char const *value);
void free_list(p_list **head);
p_list *get_node_at_index(p_list *head, unsigned int index);
unsigned int list_len(const p_list *h);
#endif
