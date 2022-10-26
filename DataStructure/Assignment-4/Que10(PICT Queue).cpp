// Q 10]. PICTQ using cpp

#include<iostream>
#define MAX 5
using namespace std;

class PICTQ
{
		int data[MAX];
		int front, rear;
		
	public:
		PICTQ()
		{
			front = rear = -1;
		}
		
		int empty()
		{
			if(front==-1 && rear==-1)
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
				if(empty())		// OR if(front==-1)
				{
					front++;
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
				
				if(front == rear)		//Queue contains only 1 element
				{
					front = rear = -1;
				}
				else					//Queue contains multiple elements
				{
					//shorfting & then rear--
					int i;
					for(i=front; i<=rear-1; i++)
					{
						data[i] = data[i+1];
					}
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
		
		void display_Q()
		{
			if(empty())
			{
				cout<<"\nQueue Empty";
				return;
			}
			cout<<"\n\nDisplaying Queue :\n";
			for(int i=front; i<=rear; i++)
			{
				cout<<" "<<data[i];
			}
		}
};

int main()
{
	PICTQ Q;
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
	
	Q.display_Q();
	
	//As we are shifting elements after dequeue, we can add another element in Queue. Which was not possible in
	//previous Simple Queue.
	Q.enqueue(70);
	Q.enqueue(80);
	
	Q.display_Q();
	return 0;
}
