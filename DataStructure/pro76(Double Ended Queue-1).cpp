// DEQueue (Double ended Queue)

#include<iostream>
#define MAX 5
using namespace std;

class DEQueue
{
		int data[MAX];
		int front, rear;
	
	public:
		DEQueue()
		{
			front = rear = -1;
		}
		
		int empty();
		int fullR();
		int fullF();
		void enqueueR(int x);
		int dequeueF();
		void enqueueF(int x);
		int dequeueR();
		void show_Q();
};

int DEQueue::empty()
{
	if(front == -1)		//OR if(rear==-1)
	{
		return 1;
	}
	return 0;
}

int DEQueue::fullR()
{
	if(rear == MAX-1)
	{
		return 1;
	}
	return 0;
}

int DEQueue::fullF()
{
	if(front == 0)
	{
		return 1;
	}
	return 0;
}

void DEQueue::enqueueR(int x)
{
	if(!fullR())
	{
		if(empty())
		{
			front++;
		}
		rear++;
		data[rear] = x;
	}
	else
	{
		cout<<"\nQueue is full from rear side";
	}
}

void DEQueue::enqueueF(int x)
{
	if(!fullF())
	{
		if(empty())
		{
			front = rear = 0;
		}
		else
		{
			front--;
		}
		data[front] = x;
	}
	else
	{
		cout<<"\nQueue is full from front side";
	}
}

int DEQueue::dequeueF()
{
	if(!empty())
	{
		int x;
		x = data[front];
		if(front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
		return x;
	}
	else
	{
		cout<<"\nQueue Empty";
		return -1;
	}
}

int DEQueue::dequeueR()
{
	if(!empty())
	{
		int x;
		x = data[rear];
		if(front == rear)
		{
			front = rear = -1;
		}
		else
		{
			rear--;
		}
		return x;
	}
	else
	{
		cout<<"\nQueue Empty";
		return -1;
	}
}

void DEQueue::show_Q()
{
	cout<<"\n\nDisplaying Queue :\n";
	if(!empty())
	{
		int i;
		for(i=front; i<=rear; i++)
		{
			cout<<" "<<data[i];
		}
	}
	else
	{
		cout<<"\nQueue Empty";
	}
}

int main()
{
	DEQueue Q;
	int x;
	
	Q.enqueueF(10);
	Q.enqueueF(20);
	Q.enqueueR(20);
	Q.enqueueR(30);
	Q.enqueueR(40);
	Q.enqueueR(50);
	Q.enqueueR(60);
	
	Q.show_Q();
	
	cout<<"\n\ndequeue element from queue :";
	x = Q.dequeueF();
	cout<<"\n"<<x;
	Q.enqueueF(70);
	x = Q.dequeueR();
	cout<<"\n"<<x;
	x = Q.dequeueF();
	cout<<"\n"<<x;
	x = Q.dequeueR();
	cout<<"\n"<<x;
	
	Q.show_Q();
	return 0;
}
