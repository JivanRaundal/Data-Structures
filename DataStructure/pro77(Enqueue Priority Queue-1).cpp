// Enqueue Priority Queue (enqueue is by priority & dequeue is normal)

#include<iostream>
#define MAX 5
using namespace std;

class EPQueue
{
		int data[MAX];
		int front, rear;
	
	public:
		EPQueue()
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
		
		void enqueueP(int x)			//enqueue by priority
		{
			if(!full())
			{
				if(empty())
				{
					front = rear = 0;
					data[rear] = x;
				}
				else
				{
					int i;
					for(i=rear; i>=front && x>data[i]; i--)
					{
						data[i+1] = data[i];
					}
					data[i+1] = x;
					rear++;
				}
			}
			else
			{
				cout<<"\nQueue Full";
			}
		}
		
		int dequeue()		//normal
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
					//front++;
					//OR shifting
					for(int i=front; i<=rear-1; i++)
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
				for(i=front ; i<=rear; i++)
				{
					cout<<" "<<data[i];
				}
			}
			else
			{
				cout<<"\nQueue Empty";
			}
		}
};

int main()
{
	EPQueue Q;
	int x;
	
	Q.enqueueP(2);
	Q.enqueueP(10);
	Q.enqueueP(7);
	Q.enqueueP(15);
	Q.enqueueP(12);
	Q.enqueueP(4);
	
	Q.show_Q();
	
	cout<<"\n\nDequeue element from queue :";
	x = Q.dequeue();
	cout<<"\n"<<x;
	x = Q.dequeue();
	cout<<"\n"<<x;
	x = Q.dequeue();
	cout<<"\n"<<x;
	
	Q.show_Q();
	Q.enqueueP(20);
	Q.enqueueP(30);
	
	return 0;
}

