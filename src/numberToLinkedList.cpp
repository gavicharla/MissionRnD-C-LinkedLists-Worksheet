/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>


struct node {
	int num;
	struct node *next;
};
struct node * create()
{
	struct node * new1 = NULL;
	new1 = (struct node *)malloc(sizeof(struct node));
	new1->next = NULL;
	return new1;
}

struct node * numberToLinkedList(int n) {
	if (n < 0)
		n *= -1;
	struct node *temp = NULL;
	struct node * head1 = NULL;
	if (n == 0)
	{

		head1 = create();
		head1->num = n;
		return head1;
	}

	while (n != 0)
	{
		if (head1 == NULL)
		{
			head1 = create();
			head1->next = NULL;
			head1->num = n % 10;
			n /= 10;
		}
		else
		{
			temp = create();
			temp->num = n % 10;
			n /= 10;
			temp->next = head1;
			head1 = temp;
			temp = NULL;
		}
	}

	return head1;
}