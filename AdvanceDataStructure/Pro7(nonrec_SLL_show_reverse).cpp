// Printing SLL in reverse order without using recursion.

#include<iostream>
#define MAX 20
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

class Stack
{
		Node* data[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(top == -1)
				return 1;
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
				cout<<"\nStack Overflow";
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
				cout<<"\nStack Underflow";
				return NULL;
			}
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
			cout<<"\nEnter data or -1 to stop : ";
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
			cout<<"\n\nPrinting list in forward direction\n";
			if(head == NULL)
			{
				cout<<"empty list";
				return;
			}
			Node * p = head;
			while(p != NULL)
			{
				cout<<"  "<<p->data;
				p = p->next;
			}
		}
		
		void nonrec_showrev()
		{
			cout<<"\n\nPrinting list in forward direction\n";
			if(head == NULL)
			{
				cout<<"empty list";
				return;
			}
			
			Stack S;
			Node * p = head;
			while(p != NULL)
			{
				S.push(p);
				p = p->next;
			}
			//printing list in reverse order
			while(!S.empty())
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
	L.nonrec_showrev();
	
	return 0;
}


