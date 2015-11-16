/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};


struct node * removeEveryKthNode(struct node *head, int K) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	struct node* temp2 = (struct node*)malloc(sizeof(struct node));
	if (K<0 || head == NULL)
		return NULL;
	int i;
	if (K>0)
		i = K;
	else  i = 0;
	int count = 0;
	temp = head;
	temp1 = head;

	while (temp != NULL)
	{
		if (i > 1)
		{
			count++;

			if (count == i)
			{
				count = 0;
				temp1->next = temp->next;
				temp2 = temp;
				temp = temp->next;
				free(temp2);
			}
			else
			{
				temp1 = temp;
				temp = temp->next;
			}
		}
		else
		{
			temp1 = temp->next;
			free(temp);
			temp = temp1;
		}
	}
	if (i == 0 || i == 1)
	{
		
		head = NULL;
	}
	return head;
}