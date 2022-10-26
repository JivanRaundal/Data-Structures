// STACK Using Linked List (SLL) in C

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}Node;

typedef struct Stack
{
	Node * top;
}Stack;

void init(Stack * ptr)
{
	ptr->top == NULL;
}

int empty(Stack * ptr)
{
	if(ptr->top == NULL)
	{
		return 1;
	}
	return 0;
}

void push(Stack * ps,int x)
{
	Node * p;
	p = (Node*) malloc(sizeof(Node));
	p->data = x;
	p->next = ps->top;
	ps->top = p;
}

int pop(Stack * ps)
{
	if(!empty(ps))
	{
		int x;
		Node * p = ps->top;
		ps->top = p->next;
		x = p->data;
		free(p);
		return x;
	}
	else
	{
		printf("\nStack Empty");
		return -1;
	}
}

int main()
{
	Stack S;
	int x;
	
	init(&S);
	
	push(&S,10);
	push(&S,20);
	push(&S,30);
	push(&S,40);
	push(&S,50);
	
	printf("\n\nUnwinding Stack :\n");
	while(!empty(&S))
	{
		x = pop(&S);
		printf(" %d",x);
	}
	return 0;
}
