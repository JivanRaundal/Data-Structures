// STACK Using Array in C

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Stack
{
	int data[MAX];
	int top;
}Stack;

void initialize(Stack * p)
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
	if(!full(p))		//or if(full(ps) == 0)
	{
		p->top++;
		p->data[p->top] = x;
	}
	else
	{
		printf("\nStack Full");
	}
}

int pop(Stack * p)
{
	if(!empty(p))
	{
		int y;
		y = p->data[p->top];
		p->top--;
		return y;
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
	
	initialize(&S);
	
	push(&S,10);
	push(&S,20);
	push(&S,30);
	push(&S,40);
	push(&S,50);
	
	printf("\n\nUnwinding Satck :\n");
	while(!empty(&S))
	{
		x = pop(&S);
		printf("%d ",x);
	}
	return 0;
}
