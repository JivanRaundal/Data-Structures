// STACK - Using Linked List (SLL)
// Note - No full() function in case of stack using Linked List. Bcz, linked list cannot be full.

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
	private:
		Node * top;			//same as head
	
	public:
		Stack()
		{
			top = NULL;
		}
		
		//Note - No full() function when implementing stack using Linked List.
		int empty();
		void push(int x);
		int pop();
		void displayStack();
};

int Stack::empty()
{
	if(top == NULL)
	{
		return 1;
	}
	return 0;
}

void Stack::push(int x)
{
	Node * p;
	p = new Node(x);
	p->next = top;
	top = p;
}

int Stack::pop()
{
	if(empty())
	{
		cout<<"\nStack Empty";
		return -1;
	}
	else
	{
		int x;
		Node * p = top;
		top = top->next;
		x = p->data;
		delete p;
		return x;
	}
}

void Stack::displayStack()
{
	cout<<"\n\nElements on stack :\n";
	Node * p = top;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

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
