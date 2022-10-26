// STACK using Array in C

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Stack
{
	int data[MAX];
	int top;
}Stack;

//prototypes
void initialize(Stack * p);
int full(Stack * ptr);
int empty(Stack * ptr);
void push(Stack * p,int x);
int pop(Stack * p);

int main()
{
	Stack S;
	int x;
	
	//initialize top
	initialize(&S);
	
	//pushing elements
	push(&S,10);
	push(&S,20);
	push(&S,30);
	push(&S,40);
	push(&S,50);
	push(&S,60);	//full
	push(&S,70);	//full
	
	//poping elements
	printf("\nUnwinding Stack :\n");
	while(!empty(&S))
	{
		x = pop(&S);
		printf(" %d",x);
	}
	
	x = pop(&S);		//empty
	printf(" %d",x);
	x = pop(&S);		//empty
	printf(" %d",x);
	return 0;
}

void initialize(Stack * p)
{
	p->top = -1;
}

int full(Stack * ptr)
{
	if(ptr->top == MAX-1)
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
	if(!full(p))	//OR if(full(p)==0)
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
		int x;
		x = p->data[p->top];
		p->top--;
		return x;
	}
	else
	{
		printf("\nStack Empty");
		return -1;
	}
}
