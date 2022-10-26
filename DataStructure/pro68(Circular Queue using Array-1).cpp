//  Circular Queue using Array :-
// Note = Try to understand different cases for display_Q() function


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
			front = rear = -1;
		}
		
		int empty()
		{
			if(front==-1 && rear==-1)	//OR if(front==-1) OR if(rear==-1)
			{
				return 1;
			}
			return 0;
		}
		
		int full()
		{
			if((rear+1)%MAX == front)		//OR if((front==0 && rear==MAX-1) || (rear+1==front))
			{
				return 1;
			}
			return 0;
		}
		
		void enqueue(int x)
		{
			if(!full())
			{
				if(empty())		//OR if(front==-1)
				{
					front = rear = 0;
				}
				else
				{
					rear = (rear+1)%MAX;
				}
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
				if(front == rear)		//Queue Contains only 1 element
				{
					front = rear = -1;
				}
				else					//Queue contains multiple elements
				{
					front = (front+1)%MAX;
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
			if(!empty())
			{
				int i = front;
				while(i != rear)
				{
					cout<<" "<<data[i];
					i = (i+1)%MAX;
				}
				cout<<" "<<data[i];		//OR cout<<data[rear]; to print last element or if list contains only 1 element 
			}
			else
			{
				cout<<"\nQueue Empty";
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
	
	cout<<"\n\nDisplaying Circular Queue :\n";
	Q.display_Q();
	
	cout<<"\n\ndequeue :\n";
	x = Q.dequeue();
	cout<<" "<<x;
	x = Q.dequeue();
	cout<<" "<<x;
	x = Q.dequeue();
	cout<<" "<<x;
	
	Q.enqueue(70);
	Q.enqueue(80);
	
	cout<<"\n\nDisplaying Circular Queue :\n";
	Q.display_Q();
	return 0;
}
