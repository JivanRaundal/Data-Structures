// Templatized Queue

#include<iostream>
#define MAX 50
using namespace std;

template<class myType>
class Queue
{
	private:
		myType data[MAX];
		int front, rear;
	public:
		Queue()
		{
			front = rear = -1;
		}
		int full()
		{
			if(rear == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(front == -1)
				return 1;
			return 0;
		}
		void enqueue(myType x)
		{
			if(!full())
			{
				if(front == -1)
				{
					front++;
				}
				rear++;
				data[rear] = x;
			}
			else
			{
				cout<<"\nQueue is full";
			}
		}
		myType Front()
		{
			return data[front];
		}
		myType dequeue()
		{
			myType x;
			if(!empty())
			{
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
				cout<<"\nQueue is empty";
				return x;
			}
		}
};

