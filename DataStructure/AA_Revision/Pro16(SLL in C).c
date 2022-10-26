// SLL in C

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
	printf("\nHow many integers ? ");
	scanf("%d", &n);
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
	printf("\n\nLIST :\n");
	if(p == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	while(p != NULL)
	{
		printf(" %d", p->data);
		p = p->next;
	}
}

void showRecursive(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	else
	{
		showRecursive(p->next);
		printf(" %d", p->data);
	}
}

int count(Node * p)
{
	if(p == NULL)
	{
		return 0;
	}
	int count=0;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

Node* addAtBeg(Node * p,int x)
{
	Node * h = (Node*) malloc(sizeof(Node));
	h->data = x;
	h->next = p;
	return h;
}

Node* addAtEnd(Node * p,int x)
{
	if(p == NULL)
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->next = NULL;
		return p;
	}
	else
	{
		Node * h = p;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = (Node*) malloc(sizeof(Node));
		p = p->next;
		p->data = x;
		p->next = NULL;
		return h;
	}
}

Node* addByPos(Node * p,int pos,int x)
{
	int n = count(p);
	if(pos<1 || pos>n+1)
	{
		printf("\nInvalid Position");
		return p;
	}
	if(pos == 1)
	{
		p = addAtBeg(p, x);
		return p;
	}
	else
	{
		Node * h = p;
		Node * q = NULL;
		int i;
		for(i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = (Node*) malloc(sizeof(Node));
		q->data = x;
		q->next = p->next;
		p->next = q;
		return h;
	}
}

Node* delAtBeg(Node * p)
{
	if(p == NULL)
	{
		return NULL;
	}
	else
	{
		Node * q = p;
		p = p->next;
		free(q);
		return p;	
	}
}

Node* delAtEnd(Node * p)
{
	if(p == NULL)
	{
		return NULL;
	}
	if(p->next == NULL)
	{
		free(p);
		return NULL;
	}
	else
	{
		Node * h = p;
		Node * q = NULL;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		free(p);
		return h;
	}
}

Node* delByPos(Node * p,int pos)
{
	int n = count(p);
	if(pos<1 || pos>n)
	{
		printf("\nInvalid Position");
		return p;
	}
	if(pos == 1)
	{
		p = delAtBeg(p);
		return p;
	}
	else
	{
		Node * h = p;
		Node * q = NULL;
		int i;
		for(i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		free(q);
		return h;
	}
}

int main()
{
	SLL L;
	L.head = NULL;
	int pos,x;
	
	L.head = create();
	show(L.head);
	printf("\n\nPrinting List in Reveresed  Order :\n");
	showRecursive(L.head);
	printf("\n\nTotal Nodes : %d",count(L.head));
	printf("\n\nEnter data to add at beg : ");
	scanf("%d", &x);
	L.head = addAtBeg(L.head, x);
	show(L.head);
	printf("\n\nEnter data to add at end : ");
	scanf("%d", &x);
	L.head = addAtEnd(L.head, x);
	show(L.head);
	printf("\n\nDeleting Data from beg : ");
	L.head = delAtBeg(L.head);
	show(L.head);
	printf("\n\nDeleting Data from end : ");
	L.head = delAtEnd(L.head);
	show(L.head);
	printf("\n\nEnter position & data to add : ");
	scanf("%d%d", &pos, &x);
	L.head = addByPos(L.head, pos, x);
	show(L.head);
	printf("\n\nEnter position & data to add : ");
	scanf("%d%d", &pos, &x);
	L.head = addByPos(L.head, pos, x);
	show(L.head);
	printf("\n\nEnter position & data to add : ");
	scanf("%d%d", &pos, &x);
	L.head = addByPos(L.head, pos, x);
	show(L.head);
	printf("\n\nEnter position to del : ");
	scanf("%d", &pos);
	L.head = delByPos(L.head, pos);
	show(L.head);
	printf("\n\nEnter position to del : ");
	scanf("%d", &pos);
	L.head = delByPos(L.head, pos);
	show(L.head);
	printf("\n\nEnter position to del : ");
	scanf("%d", &pos);
	L.head = delByPos(L.head, pos);
	show(L.head);
	return 0;
}
