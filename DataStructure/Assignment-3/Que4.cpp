// Q 4].

#include<iostream>
#include<string.h>
#include<stdlib.h>
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
	private:
		Node * head;
		
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void addatend(int x);
		void show();
		void concat(SLL T);
};

void SLL::create()
{
	char str[10];
	cout<<"\nEnter first data or 'STOP' to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	head = new Node(atoi(str));
	
	while(1)
	{
		cout<<"\nEnter next data or 'STOP' to stop : ";
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		addatend(atoi(str));
	}
}

void SLL::addatend(int x)
{
	if(head == NULL)
	{
		head = new Node(x);
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

void SLL::show()
{
	Node *p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

void SLL::concat(SLL T)
{
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = T.head;
}

int main()
{
	SLL L1,L2;
	
	cout<<"\nCreating List 1 :\n";
	L1.create();
	cout<<"\n\nLIST 1 :\n";
	L1.show();
	
	cout<<"\n\nCreating List 2 :\n";
	L2.create();
	cout<<"\n\nLIST 2 :\n";
	L2.show();
	
	L1.concat(L2);
	cout<<"\n\nAfter Concatenation List 1 :\n";
	L1.show();
	return 0;
}
