// Q 6].

#include<iostream>
#include<string>
#define MAX 5
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

class SLL
{
		Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		int addatend(int x)
		{
			if(head == NULL)
			{
				head = new Node(x);
				return head->data;
			}
			else
			{
				Node * p = head;
				while(p->next != NULL)
				{
					p = p->next;
				}
				p->next = new Node(x);
				p = p->next;
				return p->data;
			}
		}
		void show()
		{
			cout<<"\nLIST :\n";
			Node * p = head;
			while(p != NULL)
			{
				cout<<" "<<p->data;
				p = p->next;
			}
		}
};

class Stack
{
		int data[MAX];
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
		void push(int x)
		{
			if(full())
			{
				cout<<"\nStack Full";
			}
			else
			{
				top++;
				data[top] = x;
			}
		}
		int pop()
		{
			if(empty())
			{
				cout<<"\nStack Empty";
				return -1;
			}
			else
			{
				int x;
				x = data[top];
				top--;
				return x;
			}
		}
};

int main()
{
	Stack S;
	SLL L;
	int i,x;
	
	for(i=1; i<=5; i++)
	{
		cout<<"\nEnter data : ";
		cin>>x;
		S.push(L.addatend(x));
	}
	
	L.show();
	
	cout<<"\n\nUnwinding Stack :\n";
	while(!S.empty())
	{
		x = S.pop();
		cout<<" "<<x;
	}
	
	return 0;
}
