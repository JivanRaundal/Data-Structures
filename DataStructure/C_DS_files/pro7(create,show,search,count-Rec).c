// Q. SLL Non recursive create() & Recursive show(), search(), count() using C.

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
	printf("\nHow many noeds? ");
	scanf("%d", &n);
	//check valid number or not
	if(n < 1)
	{
		printf("\nInvalid Number");
		return h;
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
	printf("\nList created successfully");
	return h;
}

/*void rec_show(Node * p)		//recursive show forward 1
{
	if(p == NULL)
	{
		return;
	}
	printf("%d ", p->data);
	rec_show(p->next);
}*/

void rec_show(SLL obj)		   //recursive show forward 2
{
	if(obj.head == NULL)
	{
		return;
	}
	printf("%d ", obj.head->data);
	obj.head = obj.head->next;
	rec_show(obj);
}

void rev_rec_show(Node *p)		//recursive show in reverse order
{
	if(p == NULL)
	{
		return;
	}
	rev_rec_show(p->next);
	printf("%d ", p->data);
}

int rec_search(Node *p, int x)			//search recursively
{
	if(p == NULL)	//data not fou
	{
		return 0;	
	}
	if(p->data == x)	//data found
	{
		return 1;
	}
	else
	{
		int y = rec_search(p->next, x);		//OR return rec_search(p->next,x)
		return y;
	}
}

/*int rec_count(Node *p)		//recursive count 1
{
	static int i;
	if(p == NULL)
	{
		return i;
	}
	i++;
	return rec_count(p->next);
}*/

int rec_count(Node *p)			//recursive count 2
{
	if(p == NULL)
	{
		return 0;
	}
	return 1 + rec_count(p->next);
}

int main()
{
	SLL S1;
	S1.head = NULL;
	
	S1.head = create();
	
	printf("\n\nList in forward order :\n");
	//rec_show(S1.head);	//--(1)
	rec_show(S1);			//--(2)
	
	printf("\n\nList in reverse order :\n");
	rev_rec_show(S1.head);
	
	int x;
	printf("\n\nEnter data to be search : ");
	scanf("%d", &x);
	if(rec_search(S1.head, x))
	{
		printf("\nData Found");
	}
	else
	{
		printf("\nData Not Found");
	}
	
	printf("\n\nTotal Nodes = %d", rec_count(S1.head));
	
	return 0;
}

