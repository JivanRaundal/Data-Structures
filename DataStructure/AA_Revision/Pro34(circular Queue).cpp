// Circular Queue

#include<iostream>
#define MAX 5
using namespace std;

class CQueue
{
	private:
		int data[MAX];
		int front, rear;
	public:
		CQueue()
		{
			front = rear = -1;
		}
		int empty();
		int full();
		void enqueue(int x);
		int dequeue();
		void display();
};

int CQueue::empty()
{
	if(front == -1)
	{
		return 1;
	}
	return 0;
}

int CQueue::full()
{
	if((rear+1)%MAX == front)		//Or if((front==0 && rear==MAX-1) || (rear+1)==front)
	{
		return 1;
	}
	return 0;
}

void CQueue::enqueue(int x)
{
	if(!full())
	{
		if(front == -1)		//or if(empty())
		{
			front++;
		}
		rear = (rear+1)%MAX;
		data[rear] = x;
	}
	else
	{
		cout<<"\nQueue is full";	
	}	
}

int CQueue::dequeue()
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
			front = (front+1)%MAX;
		}
		return x;
	}
	else
	{
		cout<<"\nQueue is empty";
		return -1;
	}
}

void CQueue::display()
{
	cout<<"\n\nDisplaying Queue\n";
	if(!empty())
	{
		int i = front;
		do
		{
			cout<<data[i]<<endl;
			i = (i+1)%MAX;
		}while(i != (rear+1)%MAX);
	}
	else
	{
		cout<<"\nQueue is empty";
	}
}

int main()
{
	CQueue Q;
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.enqueue(50);
	Q.enqueue(60);
	
	Q.display();
	
	cout<<"\n\nDequeing 2 elements from Queue\n";
	cout<<Q.dequeue()<<endl;
	cout<<Q.dequeue()<<endl;
	
	Q.display();
	
	Q.enqueue(60);
	Q.enqueue(70);
	
	cout<<"\n\nDequeue all queue\n";
	while(!Q.empty())
	{
		cout<<Q.dequeue()<<"\n";
	}
	Q.dequeue();
	Q.display();
	return 0;
}

