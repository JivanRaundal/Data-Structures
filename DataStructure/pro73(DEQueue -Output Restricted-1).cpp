// // # DEQueue (Double Ended Queue)

// A] Output Restricted DEQueue (ORDQ) :-
// Note => In this queue, dequeue is possible from front side only & not from rear side.

//Functions = empty()    => : if(front==-1)  OR  : if(rear==-1)
//			  fullR()    => checks if queue is full from rear side  : if(rer==MAX-1)
//			  fullF()    => checks if queue is full from front side : if(front == 0)
//			  enqueueR() => enqueue from rear side	(rear++)
//			  enqueueF() => enqueue from front side (front--)
//			  dequeueF() => dequeue from front side (fron++) : Note - No shifting required

#include<iostream>
#define MAX 5
using namespace std;

class ORDQ
{
		int data[MAX];
		int front, rear;
	
	public:
		ORDQ()
		{
			front = rear = -1;
		}
		
		int empty()
		{
			if(front == -1)	//OR if(rear == -1)
			{
				return 1;
			}
			return 0;
		}
		
		int fullF()
		{
			if(front == 0)
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
				cout<<"\nQueue is full from rear side";
			}
		}
		
		void enqueueF(int x)
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
		
		int dequeueF()
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
					front++;		//No shifting required
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
	ORDQ L;
	int x;
	
	L.enqueueF(10);
	L.enqueueF(20);
	L.enqueueR(20);
	L.enqueueR(30);
	L.enqueueR(40);
	L.enqueueR(50);
	L.enqueueR(60);
	
	L.show_Q();
	
	cout<<"\n\nDequeue elements from queue :";
	x = L.dequeueF();
	cout<<"\n"<<x;
	x = L.dequeueF();
	cout<<"\n"<<x;
	x = L.dequeueF();
	cout<<"\n"<<x;
	
	L.show_Q();
	
	L.enqueueR(70);
	L.enqueueF(80);
	L.enqueueF(90);
	
	L.show_Q();
	
	return 0;
}


