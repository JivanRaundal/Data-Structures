// STACK using Linked List (SLL) in C

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

void initialize(Stack * p)
{
	p->top == NULL;
}

int empty(Stack * p)
{
	if(p->top == NULL)
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
	if(!empty(ps))	//OR if(empty(ps)==0)
	{
		int x;
		Node * p  =ps->top;
		ps->top = p->next;	//OR ps->top = ps->top->next;
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
	
	//initialize top to NULL
	initialize(&S);
	
	//pushing elements on stack
	push(&S,10);
	push(&S,20);
	push(&S,30);
	
	printf("\nUnwinding Stack :\n");
	x = pop(&S);
	printf(" %d",x);
	x = pop(&S);
	printf(" %d",x);
	x = pop(&S);
	printf(" %d",x);
	x = pop(&S);
	printf(" %d",x);
	
	/*while(!empty(&S))
	{
		x = pop(&S);
		printf(" %d",x);
	}*/
	return 0;
}
