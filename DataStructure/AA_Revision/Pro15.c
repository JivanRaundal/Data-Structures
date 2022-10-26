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
	struct Node *p,*head;
	int n,x,i;
	printf("How many nodes ? ");
	scanf("%d", &n);
	
	printf("Enter first data : ");
	scanf("%d",&x);
	head = (struct Node*) malloc(sizeof(struct Node));
	head->data = x;
	head->next = NULL;
	p = head;
	for(i=1; i<=n-1; i++)
	{
		printf("\nEnter next data : ");
		scanf("%d", &x);
		p->next = (struct Node*) malloc(sizeof(struct Node));
		p = p->next;
		p->data = x;
		p->next = NULL;
	}
	
	printf("\n\nPrinting List :\n");
	p = head;
	while(p != NULL)
	{
		printf(" %d",p->data);
		p = p->next;
	}
	return 0;
}
