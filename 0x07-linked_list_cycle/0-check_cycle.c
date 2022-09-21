#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *aux = list;
	listint_t *aux2 = list;

	if (list == NULL)
	{
		return (0);
	}
	while (aux && aux2 && aux2->next)
	{
		aux = aux->next;
		aux2 = aux2->next->next;
		if (aux == aux2)
			return (1);
	}
	return (0);
}
