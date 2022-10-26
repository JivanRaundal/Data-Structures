// Q 9]. Simple Queue using Linked List.
// Note = No full condition in case of linked list

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
		
		int empty()
		{
			if(front==NULL && rear==NULL)
			{
				return 1;
			}
			return 0;
		}
		
		void enqueue(int x)			//addatend() 
		{
			if(empty())
			{
				front = new Node(x);
				rear = front;
			}
			else
			{
				rear->next = new Node(x);
				rear = rear->next;
			}
		}
		
		int dequeue()
		{
			if(!empty())
			{
				int x;
				x = front->data;
				
				if(front == rear)	//list contains 1 element
				{
					delete front;
					front = rear = NULL;
				}
				else
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
		
		void display_Q()
		{
			if(empty())
			{
				cout<<"\nEmpty Queue";
				return;
			}
	
			Node * p = front;
			while(p != NULL)
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
	Q.display_Q();
	
	cout<<"\n\ndequeue :\n";
	while(!Q.empty())
	{
		x = Q.dequeue();
		cout<<" "<<x;
	}
	
	cout<<"\n\nDisplaying Queue :\n";
	Q.display_Q();
	
	return 0;
}
