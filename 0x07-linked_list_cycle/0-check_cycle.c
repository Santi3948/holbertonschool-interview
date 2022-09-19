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

	if (list == NULL)
	{
		return (0);
	}
	aux = aux->next;
	while (aux != NULL)
	{
		if (aux == list)
		{
			return (1);
		}
		aux = aux->next;
	}
	return (0);
}
