#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList()
{
	struct node *p = head;
	printf("\n[");

	//start from the begining
	while (p != NULL)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
	printf("]\n");
}
//insertion at the begining
void insertatbegin(int data)
{
	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;

	//point it to old first node
	lk->next = head;

	//point first to new first node
	head = lk;
}
void main(void)
{
	int k = 0;
	
	insertatbegin(12);
	insertatbegin(22);
	insertatbegin(30);
	insertatbegin(44);
	insertatbegin(50);
	printf("Linked list: ");

	//print list
	printList();
}
