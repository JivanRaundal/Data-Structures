//	printing linked list using recursion using Member function.
// Note :- We cannot print SLL in reverse order using LOOPS only. (we can but we have to use stack or array of pointers)
//		   But it is possible to print SLL in reverse order using RECURSION.

#include<iostream>
#include<stdlib.h>
#include<string.h>
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
		void rec_show(Node * p);
		void rec_show_rev(Node * p);
		void help_show();
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

void SLL::rec_show(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	else
	{
		cout<<" "<<p->data;
		rec_show(p->next);
	}
}

void SLL::rec_show_rev(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	else
	{
		rec_show_rev(p->next);
		cout<<" "<<p->data;
	}
}

void SLL::help_show()
{
	cout<<"\nList in forward order using recursion :\n";
	rec_show(head);		//here, head will be of calling object of help_show() function
	cout<<"\nList in reverse order using recursion :\n";
	rec_show_rev(head);
}

int main()
{
	SLL obj;
	obj.create();
	obj.help_show();
	return 0;
}
