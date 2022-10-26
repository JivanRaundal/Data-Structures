// # DEQueue (Double Ended Queue)

// A] Input Restricted DEQueue (IRDQ) :-
// Note => In this queue, enqueue is possible from rear side only & not from front side.

//Functions = empty()    => if(front==-1) OR if(rear==-1)
//			  fullR()    => checks if queue is full from rear side : if(rear == MAX-1)
//			  enqueueR() => enqueue from rear side	(rear++)
//			  dequeueF() => dequeue from front side (fron++) OR (front=0) always bcz of shifting lo left.
//			  dequeueR() => dequeue from rear side (rear--)

#include<iostream>
#define MAX 5
using namespace std;

class IRDQ
{
		int data[MAX];
		int front, rear;
	
	public:
		IRDQ()
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
		
		int fullR()
		{
			if(rear == MAX-1)
			{
				return 1;
			}
			return 0;
		}
		
		void enqueueR(int x)
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
				cout<<"\nQueue Full";
			}
		}
		
		int dequeueF()
		{
			if(!empty())
			{
				int x;
				x = data[front];
				if(front == rear)	//Q contains only 1 element
				{
					front = rear = -1;
				}
				else
				{
					//front++;
					//OR Shifting (front=0) always
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
		
		int dequeueR()
		{
			if(!empty())
			{
				int x;
				x = data[rear];
				if(front == rear)		//Q contains only 1 element
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
		
		void show_Q()
		{
			cout<<"\n\nDisplaying Queue :\n";
			if(!empty())
			{
				for(int i=front; i<=rear; i++)
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
	IRDQ Q;
	int x;
	
	Q.enqueueR(10);
	Q.enqueueR(20);
	Q.enqueueR(30);
	Q.enqueueR(40);
	Q.enqueueR(50);
	Q.enqueueR(60);
	
	Q.show_Q();
	
	cout<<"\n\nDequeue elements from queue :";
	x = Q.dequeueF();
	cout<<"\n"<<x;
	
	Q.enqueueR(80);
	
	x = Q.dequeueR();
	cout<<"\n"<<x;
	x = Q.dequeueF();
	cout<<"\n"<<x;
	x = Q.dequeueR();
	cout<<"\n"<<x;
	
	Q.show_Q();
	
	Q.enqueueR(60);
	Q.enqueueR(70);
	
	Q.show_Q();
	return 0;
}

