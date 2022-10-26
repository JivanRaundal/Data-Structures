// Solve-3.txt Q6]

#include<iostream>
#define MAX 20
using namespace std;

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

//Linked list (SLL)
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
	private:
		Node * head;
	public:
		SLL()
		{
			head = NULL;
		}
		int addAtEnd(int x)
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
};

int main()
{
	Stack S;
	SLL L;
	int x,n;
	cout<<"\nHow many nodes ? ";
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cout<<"\nEnter data : ";
		cin>>x;
		S.push(L.addAtEnd(x));
	}
	cout<<"\n\nPrinting List in reverese order using stack :\n";
	while(!S.empty())
	{
		cout<<S.pop()<<endl;
	}
	return 0;
}




