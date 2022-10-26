//Stack using SLL

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
		Node * top;
	public:
		Stack()
		{
			top = NULL;
		}
		int empty();
		void push(int x);				//same as addatbeg(int x);
		int pop();						//same as delatbeg();
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
	//No full condition for stack using Linked List
	Node * p = new Node(x);
	p->next = top;
	top = p;
}

int Stack::pop()
{
	if(empty())	
	{
		cout<<"\nStackunderflow";
		return -1;
	}
	else
	{
		Node * p = top;
		int x = top->data;
		top = top->next;
		delete p;
		return x;
	}
}

void Stack::displayStack()
{
	if(empty())
	{
		cout<<"\nStack is Empty";
		return;
	}
	else
	{
		for(Node* p=top; p!=NULL; p=p->next)
		{
			cout<<"\n"<<p->data;
		}
	}
}

int main()
{
	Stack S;
	int i,x;
	int num[5] = {6,8,10,17,90};
	for(i=0; i<5; i++)
	{
		S.push(num[i]);
		S.displayStack();
		cout<<"\n--------";
	}
	//S.displayStack();
	cout<<"\n\nUnwinding Stack\n";
	while(!S.empty())
	{
		x = S.pop();
		cout<<x<<"\n";
	}
	S.displayStack();
	return 0;
}
