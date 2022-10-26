//Stack using array in C language :

#include<stdio.h>
#define MAX 10

typedef struct Stack
{
	int data[MAX];
	int top;
}Stack;

void initialize(Stack * st)
{
	st->top = -1;
}

int full(Stack * st)
{
	if(st->top == MAX-1)
	{
		return 1;
	}
	return 0;
}

int empty(Stack * st)
{
	if(st->top == -1)
	{
		return 1;
	}
	return 0;
}

void push(Stack * st,int x)
{
	if(full(st))
	{
		printf("\nStackoverflow");
	}
	else
	{
		st->top++;
		st->data[st->top] = x;
	}
}

int pop(Stack * st)
{
	if(empty(st))
	{
		printf("\nStackunderflow");
		return -1;
	}
	else
	{
		int x = st->data[st->top];
		st->top--;
		return x;
	}
}

int main()
{
	Stack S;
	//initialize(S);			//error, due to pass by value changes made in initialize() method will not get reflected in S of main()
	initialize(&S);				//pass by address
	int x;
	printf("\nKeep Entering values\n");
	while(!full(&S))
	{
		scanf("%d",&x);
		push(&S,x);
	}
	printf("\n\nUnwinding Stack\n");
	while(!empty(&S))
	{
		x = pop(&S);
		printf("%d\n",x);
	}
	return 0;
}
