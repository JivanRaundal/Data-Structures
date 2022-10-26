// Q 4].

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Stack
{
	int data[MAX];
	int top;
}Stack;

void init(Stack * p)
{
	p->top = -1;
}

int full(Stack * p)
{
	if(p->top == MAX-1)
	{
		return 1;
	}
	return 0;
}

int empty(Stack * p)
{
	if(p->top == -1)
	{
		return 1;
	}
	return 0;
}

void push(Stack * p,int x)
{
	if(full(p))
	{
		printf("\nStack Full");
	}
	else
	{
		p->top++;
		p->data[p->top] = x;
	}
}

int pop(Stack * p)
{
	if(empty(p))
	{
		printf("\nStack Empty");
		return -1;
	}
	else
	{
		int x;
		x = p->data[p->top];
		p->top--;
		return x;
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
	push(&S,60);
	
	printf("\nUnwinding Stack :\n");
	while(!empty(&S))
	{
		x = pop(&S);
		printf(" %d",x);
	}
	return 0;
}
