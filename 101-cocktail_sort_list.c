/*
* File: 101-cocktail_sort_list.c
* Auth: Anas Jelloul
*/

#include "sort.h"

void switch_node_ahead(listint_t **list, listint_t **tl, listint_t **skr);
void switch_node_behind(listint_t **list, listint_t **tl, listint_t **skr);
void cocktail_sort_list(listint_t **list);

/**
* switch_node_ahead - switch a node in a listint_t doubly-linked
* @list: pointer to head_doubly-linked list of integers.
* @tl: pointer to tail_the doubly-linked list.
* @shkr: pointer to current switchping node of the cocktail.
*/
void switch_node_ahead(listint_t **list, listint_t **tl, listint_t **shkr)
{
listint_t *_temp = (*shkr)->next;

if ((*shkr)->prev != NULL)
(*shkr)->prev->next = _temp;
else
*list = _temp;
_temp->prev = (*shkr)->prev;
(*shkr)->next = _temp->next;
if (_temp->next != NULL)
_temp->next->prev = *shkr;
else
*tl = *shkr;
(*shkr)->prev = _temp;
_temp->next = *shkr;
*shkr = _temp;
}

/**
* switch_node_behind - switch a node in a listint_t doubly-linked
* @list: pointer to head_doubly-linked list of integers.
* @tl: pointer to tail_the doubly-linked list.
