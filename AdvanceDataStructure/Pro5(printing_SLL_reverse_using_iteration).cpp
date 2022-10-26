// Printing SLL in reverse order without using recursion. i.e. we have to use iteration (loop) with the help of stack.

#include<iostream>
#define MAX 20
using namespace std;

class Node;			//forward declaration

class Stack
{
		Node* data[MAX];			//stack will store addresses of Node class objects
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top == MAX-1)
			{
				return 1;
			}
			return 0;
		}
		int empty()
		{
			if(top == -1)
			{
				return 1;
			}
			return 0;
		}
		void push(Node * p)
		{
			if(!full())
			{
				top++;
				data[top] = p;
			}
			else
			{
				cout<<"\nStack is full";
			}
		}
		Node* pop()
		{
			if(!empty())
			{
				Node * p;
				p = data[top];
				top--;
				return p;
			}
			else
			{
				cout<<"\nStack is empty";
				return NULL;
			}
		}
};

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

class SLL
{
		Node * head;
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create()
		{
			head = rec_create();
		}
		Node* rec_create()
		{
			int x;
			cout<<"\nEnter data or -1 to STOP : ";
			cin>>x;
			if(x == -1)
			{
				return NULL;
			}
			Node * p;
			p = new Node(x);
			p->next = rec_create();
			return p;
		}
		void show()
		{
			cout<<"\n\nPrinting list in forward order\n";
			if(head == NULL)
			{
				cout<<"Empty List";
				return;
			}
			Node * p = head;
			while(p != NULL)
			{
				cout<<"  "<<p->data;
				p = p->next;
			}
		}
		void show_rev()					//to print SLL in reverse order using iteration by using stack
		{
			if(head == NULL)
			{
				return;
			}
			//first will traverse SLL and push addresses of each node on stack
			Stack S;
			Node * p = head;
			while(p != NULL)
			{
				S.push(p);
				p = p->next;	
			}
			//printing SLL in reverse order
			cout<<"\n\nPrinting list in reverse order\n";
			while(!S.empty())		//i.e. while stack not empty
			{
				p = S.pop();
				cout<<"  "<<p->data;	
			}
		}
};

int main()
{
	SLL L;
	L.create();
	L.show();
	L.show_rev();
	
	return 0;
}
