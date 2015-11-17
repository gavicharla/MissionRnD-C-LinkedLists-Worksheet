/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node *get_tail(struct node *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}
struct node *partition(struct node *head, struct node *end, struct node **newhead, struct node **newend)
{
	struct node *pivot = end;
	struct node *prev = NULL, *cur = head, *tail = pivot;
	while (cur != pivot)
	{
		if (cur->num < pivot->num)
		{
			if ((*newhead) == NULL)
				(*newhead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
		{
			if (prev)
				prev->next = cur->next;
			struct node *temp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}
	if ((*newhead) == NULL)
		(*newhead) = pivot;
	(*newend) = tail;

	return pivot;
}

struct node *quickSort1(struct node *head, struct node *end)
{
	if (!head || head == end)
		return head;

	node *newhead = NULL, *newend = NULL;
	struct node *pivot = partition(head, end, &newhead, &newend);
	if (newhead != pivot)
	{
		struct node *tmp = newhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		newhead = quickSort1(newhead, tmp);
		tmp = get_tail(newhead);
		tmp->next = pivot;
	}
	pivot->next = quickSort1(pivot->next, newend);

	return newhead;
}

struct node * quickSort(struct node **headRef)
{
	(*headRef) = quickSort1(*headRef, get_tail(*headRef));
	return *headRef;
}

struct node * sortLinkedList(struct node * head)
{
	if (!head)
		return NULL;
	else if (head->next == NULL)
		return head;
	struct node * temp = head;
	struct node * temp1 = NULL;

	temp1 = quickSort(&head);
	return temp1;
}