/*
* File: 1-insertion_sort_list.c
* Auth: Anas Jelloul
*/

#include "sort.h"

/**
 * switch_nds - Switch a listint_t doubly-linked list.
 * @lst: A pointer in head of doubly-linked list.
 * @nd1: A pointer in first node to switch.
 * @nd2: The second node to switch.
 */
void switch_nds(listint_t **lst, listint_t **nd1, listint_t *nd2)
{
(*nd1)->next = nd2->next;
if (nd2->next != NULL)
nd2->next->prev = *nd1;
nd2->prev = (*nd1)->prev;
nd2->next = *nd1;
if ((*nd1)->prev != NULL)
(*nd1)->prev->next = nd2;
else
*lst = nd2;
(*nd1)->prev = nd2;
*nd1 = nd2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints a list after every switch.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *iterator, *insrt, *temp_;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (iterator = (*list)->next; iterator != NULL; iterator = temp_)
{
temp_ = iterator->next;
insrt = iterator->prev;
while (insrt != NULL && iterator->n < insrt->n)
{
switch_nds(list, &insrt, iterator);
print_list((const listint_t *)*list);
}
}
}
