// Dequeue Priority Queue (dequeue is by priority & enqueue is normal)

#include<iostream>
#define MAX 5
using namespace std;

class DPQueue
{
		int data[MAX];
		int front, rear;
		
	public:
		DPQueue()
		{
			front = rear = -1;
		}
		
		int empty()
		{
			if(front == -1)
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
		
		void enqueue(int x)		//Normal
		{
			if(!full())
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
				cout<<"\nQueue Full";
			}
		}
		
		int largest()		//this function will return index of largest element
		{
			int i,ind,max;
			max = data[0];
			ind = front;
			for(i=front; i<=rear; i++)
			{
				if(max < data[i])
				{
					max = data[i];
					ind = i;
				}
			}
			return ind;
		}
		
		int dequeueP()
		{
			if(!empty())
			{
				int x;
				if(front == rear)
				{
					x = data[front];
					front = rear = -1;
				}
				else
				{
					int i,ind;
					ind = largest();
					x = data[ind];
					
					for(i=ind; i<rear; i++)
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
		
		void show_Q()
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
				cout<<"\nEmpty Queue";
			}
		}
};

int main()
{
	DPQueue Q;
	int x;
	
	Q.enqueue(2);
	Q.enqueue(10);
	Q.enqueue(7);
	Q.enqueue(15);
	Q.enqueue(12);
	Q.enqueue(4);
	
	Q.show_Q();
	
	cout<<"\n\nDequeue element from queue :";
	x = Q.dequeueP();
	cout<<"\n"<<x;
	x = Q.dequeueP();
	cout<<"\n"<<x;
	x = Q.dequeueP();
	cout<<"\n"<<x;
	
	Q.show_Q();
	Q.enqueue(20);
	Q.enqueue(30);
	
	Q.show_Q();
	return 0;
}

