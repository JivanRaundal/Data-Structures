// Q 1]. Create a SLL using C. Write a nonrecursive function deleteallnodes() to delete all nodes in a list and make
//		 your list empty.

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
	if(n < 1)
	{
		printf("\nInvalid Number");
		return NULL;
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
	printf("\nCreated Successfully");
	return h;
}

void show(Node *p)
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

Node* delallnodes(Node *p)
{
	Node * q = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return NULL;	//or return p;	(p will NULL at last)
}

int main()
{
	SLL S;
	S.head = NULL;
	
	S.head = create();
	printf("\n\nLISt :\n");
	show(S.head);
	
	S.head = delallnodes(S.head);
	printf("\n\nLISt :\n");
	show(S.head);
	
	return 0;
}
