// Simle Queue using Linked List (SLL or CLL)
// Note = No full condition for Queue using Linked List

#include<iostream>
using namespace std;

class Node
{	
	public:
		int data;
		Node * next;
		
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int x)
		{
			data = x;
			next = NULL;
		}
};

class Queue
{
		Node *front, *rear;
	
	public:
		Queue()
		{
			front = rear = NULL;
		}
		
		// Note = No full condition for Queue using Linked List
		
		int empty()
		{
			if(front==NULL && rear==NULL)	//OR if(front==NULL) OR if(rear==NULL)
			{
				return 1;
			}
			return 0;
		}
		
		void enqueue(int x)					//same as addatend() in SLL or CLL
		{
			//No full condition in case of Q using Linked List
			if(front==NULL)					//OR if(empty())
			{
				front = new Node(x);
				rear  = front;
			}
			else
			{
				rear->next = new Node(x);
				rear = rear->next;
			}
		}
		
		int dequeue()						//same as delatbeg() in SLL or CLL
		{
			if(!empty())
			{
				int x;
				x = front->data;
				
				if(front==rear)				//Queue contains only 1 element
				{
					delete front;			//OR delete rear
					front = rear = NULL;
				}
				else						//Queue contains multiple element
				{
					Node * p = front;
					front = front->next;
					delete p;
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
			if(empty())
			{
				cout<<"Queue Empty";
				return;
			}
			
			Node * p = front;
			while(p != NULL)			//OR while(p != rear->next)
			{
				cout<<" "<<p->data;
				p = p->next;
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
	
	cout<<"\n\nDisplaying Queue :\n";
	Q.show_Q();
	
	cout<<"\n\ndequeue :\n";
	while(!Q.empty())
	{
		x = Q.dequeue();
		cout<<" "<<x;
	}
	
	cout<<"\n\nDisplaying Queue :\n";
	Q.show_Q();
	
	return 0;
}
