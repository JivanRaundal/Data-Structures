// Q 5]. Stack Using array through C

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

int empty(Stack * p)
{
	if(p->top == -1)
	{
		return 1;
	}
	return 0;
}

int full(Stack * p)
{
	if(p->top == MAX-1)
	{
		return 1;
	}
	return 0;
}

void push(Stack * p,int x)
{
	if(!full(p))
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

void displayStack(Stack * p)
{
	if(empty(p))
	{
		printf("\nStack Empty");
		return;	
	}
	printf("\nDisplaying Stack :\n");
	int i;
	for(i=0; i<=p->top; i++)
	{
		printf(" %d", p->data[i]);
	}
}

int main()
{
	int num[6] = {6,8,10,24,37,55};
	int i,x;
	
	Stack S;
	init(&S);
	
	//pushing array elements on stack
	for(i=0; i<6; i++)
	{
		push(&S,num[i]);
	}
	
	displayStack(&S);
		
	printf("\n\nUnwinding Satck :\n");
	while(!empty(&S))		//OR while(S.empty==0)
	{
		x = pop(&S);
		printf(" %d",x);
	}
	return 0;
}
