// Q 4]. Create SLL. creat(), show().
//		 Sort SLL in ascending order.

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
		void addatend(int x);
		void show();
		void sort();
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
	if(head == NULL)
	{
		cout<<"\nEmpty List.";
		return;
	}
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

void SLL::sort()
{
	Node * p = head;
	Node * q;
	while(p != NULL)
	{
		q = p->next;
		while(q != NULL)
		{
			if(p->data > q->data)
			{
				int temp;
				temp    = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

int main()
{
	SLL L;
	L.create();
	cout<<"\\nList before sorting :\n";
	L.show();
	
	L.sort();
	cout<<"\n\nList after sorting :\n";
	L.show();
	
	return 0;
}
