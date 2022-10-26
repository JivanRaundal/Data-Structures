// Q. Write a C program to create n nodes using create() function.
// Node :- use typedef()

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}Node;

typedef struct SLL
{
	Node * head;
}SLL;

Node* create()
{
	Node * h = NULL;
	Node * p = NULL;
	int n,x,i;
	
	printf("\nHow many nodes? ");
	scanf("%d", &n);
	//check n is valid or not
	if(n < 1)
	{
		printf("\nInvalid Number");
		return h;	//check returntype of create() function
	}
	printf("\nEnter first data : ");
	scanf("%d", &x);
	h = (Node*) malloc(sizeof(Node));
	h->data = x;
	h->next = NULL;
	
	p = h;
	for(i=1; i<=n-1; i++)
	{
		printf("\nEnter next data : ");
		scanf("%d", &x);
		p->next = (Node*) malloc(sizeof(Node));
		p = p->next;
		p->data = x;
		p->next = NULL;
	}
	return h;
}

void show(Node * p)
{
	if(p == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int count(Node *p)		// without passing 0
{
	static int i;
	if(p == NULL)
	{
		return i;
	}
	i++;
	return count(p->next);
}

/*int count(Node *p, int i)		// with passing 0
{
	if(p == NULL)
	{
		return i;
	}
	return count(p->next, i+1);
}*/

int main()
{
	SLL L;
	L.head = NULL;
	
	L.head = create();
	
	printf("\n\nLIST :\n");
	show(L.head);
	
	//printf("\nTotal Nodes = %d", count(L.head,0));	//with passing 0 
	printf("\nTotal Nodes = %d", count(L.head));		//without passing 0
	return 0;
}

