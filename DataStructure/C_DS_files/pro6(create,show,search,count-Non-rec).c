// Q. SLL Non-recursive create(), show(), search(), count() using C.

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
	//check valid n or not
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

/*void show(Node * p)		//Non recursive
{
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}*/

void show(SLL obj)
{
	while(obj.head != NULL)
	{
		printf("%d ", obj.head->data);
		obj.head = obj.head->next;
	}
}


int search(Node *p,int x)		//nNon recursive
{
	while(p != NULL)
	{
		if(p->data == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int count(Node *p)
{
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int main()
{
	SLL S1;
	S1.head = NULL;
	
	S1.head = create();
	printf("\n\nLIST :\n");
	//show(S1.head);
	show(S1);
	
	int x;
	printf("\n\nEnter data to be searched :");
	scanf("%d", &x);
	if(search(S1.head, x))
	{
		printf("\nData Found");
	}
	else
	{
		printf("\nData Not Found");
	}
	
	printf("\n\nTotal Number of Nodes = %d", count(S1.head));
	
	return 0;
}

