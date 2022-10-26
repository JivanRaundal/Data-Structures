// Q. Write a C program to create n nodes.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

int main()
{
	struct Node * head = NULL;
	struct Node * p = NULL;
	int n,x,i;
	
	printf("\nHow many nodes? ");
	scanf("%d", &n);
	
	printf("\nEnter first data : ");
	scanf("%d", &x);
	head = (struct Node*) malloc(sizeof(struct Node));
	head->data = x;
	head->next = NULL;
	
	p = head;
	for(i=1; i<=n-1; i++)
	{
		puts("\nEnter next data : ");
		scanf("%d", &x);
		p->next = (struct Node*) malloc(sizeof(struct Node));
		// 2 opitions to add data into new object
		/* 1] add data then change p
		p->next->data = x;
		p->next->next = NULL; */
		// 2] change p then add data (easy)
		p = p->next;
		p->data = x;
		p->next = NULL;
	}
	
	//printing list
	printf("\n\nLIST :\n");
	p = head;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return 0;
}
