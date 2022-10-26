// SLL through C

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

int main()
{
	struct Node * p = NULL;
	p = (struct Node*) malloc(sizeof(struct Node));
	p->next = (struct Node*) malloc(sizeof(struct Node));
	p->next->next = (struct Node*) malloc(sizeof(struct Node));
	p->next->next->next = NULL;
	
	puts("\nEnter 3 values :\n");
	scanf("%d", &(p->data));
	scanf("%d", &(p->next->data));
	scanf("%d", &(p->next->next->data));
	
	printf("\n\nPrinting values :\n");
	struct Node * q = p;
	while(q != NULL)
	{
		printf(" %d",q->data);
		q = q->next;
	}
	return 0;
}
