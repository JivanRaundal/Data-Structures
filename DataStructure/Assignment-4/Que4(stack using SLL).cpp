// Q 4]. Stack using Linked List
// Note = No full condition for stack using Linked List
// LIFO (last-in-first-out)

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

class Stack
{
		Node * top;
	
	public:
		Stack()
		{
			top = NULL;
		}
		
		int empty()
		{
			if(top == NULL)
			{
				return 1;
			}
			return 0;
		}
		
		void push(int x)		//addatbeg() in SLL
		{
			Node * p;
			p = new Node(x);
			p->next = top;
			top = p;
		}
		
		int pop()				//delatbeg() in SLL
		{
			if(!empty())
			{
				int x;
				Node * p = top;
				top = top->next;
				x = p->data;
				delete p;
				return x;
			}
			else
			{
				cout<<"\nStack Empty";
				return -1;
			}
		}
		
		void displayStack()
		{
			cout<<"\n\nDisplaying Stack :\n";
			Node * p = top;
			while(p != NULL)
			{
				cout<<" "<<p->data;
				p = p->next;
			}
		}
};

int main()
{
	int num[6] = {6,8,10,24,37,55};
	Stack S;
	int i,x;
	
	//pushing array elements on stack
	for(i=0; i<6; i++)
	{
		S.push(num[i]);
	}
	
	S.displayStack();
		
	cout<<"\n\nUnwinding Satck :\n";
	while(!S.empty())		//OR while(S.empty==0)
	{
		x = S.pop();
		cout<<" "<<x;
	}
	return 0;
}
