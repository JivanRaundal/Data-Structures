// updated create() function

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
		Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void show();
		void addatend(int x);
};

void SLL::create()
{
	int x;
	cout<<"\nEnter first data or -1 to stop : ";
	cin>>x;
	if(x == -1)
	{
		return;
	}
	head = new Node(x);
	
	while(1)
	{
		cout<<"\nEnter next data or -1 to stop : ";
		cin>>x;
		if(x == -1)
		{
			break;
		}
		addatend(x);
	}
}

void SLL::show()
{
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

void SLL::addatend(int x)
{
	Node * p = NULL;
	if(head==NULL)
	{
		head = new Node(x);
	}
	else
	{
		p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

int main()
{
	SLL S;
	int x;
	
	S.create();
	cout<<"\nLIST\n";
	S.show();
}
