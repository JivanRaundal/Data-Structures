// Stack using SLL in C

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

void init(Stack * p)
{
	p->top = NULL;
}

int empty(Stack * p)
{
	if(p->top == NULL)
	{
		return 1;
	}
	return 0;
}

void push(Stack * st,int x)
{
	//No full condition in SLL
	Node * p = (Node*) malloc(sizeof(Node));
	p->data = x;
	p->next = st->top;
	st->top = p;
}

int pop(Stack * st)
{
	if(empty(st))
	{
		printf("\nStack Empty");
		return -1;
	}
	else
	{
		Node * p = st->top;
		int x = p->data;
		st->top = st->top->next;
		free(p);
		return x;
	}
}

int main()
{
	Stack S;
	init(&S);
	push(&S,10);
	push(&S,20);
	push(&S,30);
	push(&S,40);
	push(&S,50);
	
	int x;
	printf("\n\nUnwinding Stack\n");
	while(!empty(&S))
	{
		x = pop(&S);
		printf("%d\n",x);
	}
	
	return 0;
}
