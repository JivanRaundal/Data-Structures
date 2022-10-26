// Simple Queue
// Queue Principle => First in First Out (FIFO)

#include<iostream>
#define MAX 5
using namespace std;

class Queue
{
		int data[MAX];
		int front, rear;
	
	public:
		Queue()
		{
			front = -1;
			rear  = -1;
		}
		
		int empty()
		{
			if(front==-1 && rear==-1)		//OR if(front==-1) OR if(rear==-1)
			{
				return 1;
			}
			return 0;
		}
		
		int full()
		{
			if(rear == MAX-1)
			{
				return 1;
			}
			return 0;
		}
		
		void enqueue(int x)
		{
			if(!full())
			{
				if(front==-1)		//OR if(empty()) i.e. if Q is empty, front will also change to 0
				{
					front++;		//OR front=0;
				}
				rear++;
				data[rear] = x;
			}
			else
			{
				cout<<"\nQueue Full";
			}
		}
		
		int dequeue()
		{
			if(!empty())
			{
				int x;
				x = data[front];
				if(front==rear)			//i.e. if Queue contains only 1 element, Both front & rear will become -1
				{
					front = rear = -1;
				}
				else					//i.e. if Queue contains multiple elements, then only front will change
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
		
		void display_Q()
		{
			cout<<"\n\nDisplay Queue :\n";
			int i;
			for(i=front; i<=rear; i++)
			{
				cout<<" "<<data[i];
			}
		}
};

int main()
{
	Queue Q;
	int x;
	
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.enqueue(50);
	Q.enqueue(60);
	
	Q.display_Q();
	
	cout<<"\n\ndequeue :\n";
	x = Q.dequeue();
	cout<<" "<<x;
	x = Q.dequeue();
	cout<<" "<<x;
	x = Q.dequeue();
	cout<<" "<<x;
	
	//Although we have removed 3 elements from Q, Q is still full, this is the drawback of Simple Queue
	Q.enqueue(70);
	
	Q.display_Q();
	return 0;
}


