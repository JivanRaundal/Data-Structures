// Q.12] SLL

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
		void show();
		void show_rec(Node * p);
		void addatbeg(int x);
		void addatend(int x);
		void delatbeg();
		void delatend();
		void sort();
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList already exists";
		return;
	}
	char str[10];
	cout<<"\nKeep entering numbers and enter 'STOP' to stop :\n";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	head = new Node(atoi(str));
	Node * p = head;
	while(1)
	{
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			return;
		}
		p->next = new Node(atoi(str));
		p = p->next;
	}
}

void SLL::show()
{
	cout<<"\n\nLIST :\n";
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
	
	cout<<"\nRecursive Show in reverse order :\n";
	show_rec(head);
}

void SLL::show_rec(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	show_rec(p->next);
	cout<<" "<<p->data;			//during backtracking in reverese order
}

void SLL::addatbeg(int x)
{
	Node * p;
	p = new Node(x);
	p->next = head;
	head = p;
}

void SLL::addatend(int x)
{
	if(head == NULL)
	{
		head = new Node(x);
	}
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = new Node(x);
}

void SLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\ncan't delete. empty list";
		return;
	}
	Node * p = head;
	head = head->next;
	delete p;
}

void SLL::delatend()
{
	if(head == NULL)
	{
		cout<<"\ncan't delete. empty list";
		return;		
	}
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	Node * p = head;
	Node * q;
	while(p->next != NULL)
	{
		q = p;
		p = p->next;
	}
	q->next = NULL;
	delete p;
}

void SLL::sort()
{
	if(head == NULL)
	{
		cout<<"\nCan't sort empty list";
	}
	Node * p = head;
	Node * q = NULL;
	while(p != NULL)
	{
		q = p->next;
		while(q != NULL)
		{
			if(p->data > q->data)
			{
				//swapping
				int temp = p->data;
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
	L.show();
	L.addatbeg(10);
	L.show();
	L.addatend(60);
	L.show();
	L.delatbeg();
	L.show();
	L.delatend();
	L.show();
	L.sort();
	L.show();
	
	return 0;
}



