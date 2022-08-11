#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
 
 /**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: the head of the list
 * @number: the index where the node is insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *aux;
    listint_t *new_node;

    if (head == NULL)
    {
        return NULL;
    }
    aux = *head;
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    if (*head == NULL)
    {
        new_node->next = NULL;
        *head = new_node;
        return (*head);
    }
    while (aux != NULL)
    {
        if (number > aux->n && aux->next != NULL && number < aux->next->n)
        {
            new_node->next = aux->next;
            aux->next = new_node;
            return (new_node);
        }
        if (number < aux->n)
        {
            new_node->next = aux;
        }
        if (aux->next == NULL)
        {
            aux->next = new_node;
            new_node->next = NULL;
            return (new_node);
        }
        aux = aux->next;
    }
    return NULL;
}