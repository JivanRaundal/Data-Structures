// Simple Queue Through C

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Queue
{
	int data[MAX];
	int front, rear;
}Queue;

void init(Queue * p)	//initialize front & rear
{
	p->front = -1;
	p->rear  = -1;
}

int empty(Queue * p)
{
	if(p->front == -1)	//OR if(p->rear == -1)
	{
		return 1;
	}
	return 0;
}

int full(Queue * p)
{
	if(p->rear == MAX-1)
	{
		return 1;
	}
	return 0;
}

void enqueue(Queue * p,int x)
{
	if(!full(p))
	{
		if(p->front == -1)	//OR if(empty(p))
		{
			p->front++;
		}
		p->rear++;
		p->data[p->rear] = x;
	}
	else
	{
		printf("\nQueue Full");
	}
}

int dequeue(Queue * p)
{
	if(!empty(p))
	{
		int x;
		x = p->data[p->front];
		if(p->front == p->rear)		//if Queue contains only 1 element
		{
			p->front = p->rear = -1;
		}
		else
		{
			//p->front++;
			// OR go with shifting
			int i;
			for(i=p->front; i<=p->rear-1; i++)
			{
				p->data[i] = p->data[i+1];
			}
			p->rear--;
		}
		return x;
	}
	else
	{
		printf("\nQueue Empty");
		return -1;
	}
}

void show_Q(Queue * p)
{
	printf("\n\nDisplaying Queue :\n");
	if(!empty(p))
	{
		int i;
		for(i=p->front; i<=p->rear; i++)
		{
			printf(" %d", p->data[i]);
		}
	}
	else
	{
		printf("\nEmpty Queue");
	}
}

int main()
{
	Queue Q;
	int x;
	
	init(&Q);
	
	enqueue(&Q,10);
	enqueue(&Q,20);
	enqueue(&Q,30);
	enqueue(&Q,40);
	enqueue(&Q,50);
	enqueue(&Q,60);
	
	show_Q(&Q);
	
	printf("\n\nDequeue elements from Queue :");
	x = dequeue(&Q);
	printf("\n%d",x);
	x = dequeue(&Q);
	printf("\n%d",x);
	x = dequeue(&Q);
	printf("\n%d",x);
	
	show_Q(&Q);
	
	enqueue(&Q,70);
	enqueue(&Q,80);
	
	show_Q(&Q);
	return 0;
}


