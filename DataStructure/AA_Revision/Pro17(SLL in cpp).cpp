// SLL in CPP

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
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
		int count();
		int search(int x);
		void addAtBeg(int x);
		void addAtEnd(int x);
		void addByPos(int pos,int x);
		void delAtBeg();
		void delAtEnd();
		void delByPos(int pos);
};

/*void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Already Created";
		return;
	}
	int x,n,i;
	cout<<"\nHow many nodes? ";
	cin>>n;
	if(n == 0)
	{
		return;
	}
	cout<<"\nEnter first data : ";
	cin>>x;
	head = new Node(x);
	Node * p = head;
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next data : ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;
	}
	cout<<"\nList Created";
}
*/

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Already Created";
		return;
	}
	char str[10];
	int x;
	cout<<"\nEnter data or STOP to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	x = atoi(str);
	head = new Node(x);
	Node * p = head;
	while(1)
	{
		cout<<"\nEnter data or STOP to stop : ";
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		x = atoi(str);
		p->next = new Node(x);
		p = p->next;
	}
	cout<<"\nList Created Successfully";
}

void SLL::show()
{
	cout<<"\n\nLIST :\n";
	if(head == NULL)
	{
		cout<<"Empty List";
	}
	else
	{
		Node * p = head;
		while(p != NULL)
		{
			cout<<" "<<p->data;
			p = p->next;
		}
	}
}

int SLL::count()
{
	if(head == NULL)
	{
		return 0;
	}
	Node * p = head;
	int count = 0;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int SLL::search(int x)
{
	if(head == NULL)
	{
		return 0;
	}
	Node * p = head;
	while(p != NULL)
	{
		if(p->data == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void SLL::addAtBeg(int x)
{
	Node * p = new Node(x);
	p->next = head;
	head = p;
}

void SLL::addAtEnd(int x)
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

void SLL::addByPos(int pos,int x)
{
	int n = this->count();
	if(pos<1 || pos>n+1)
	{
		cout<<"Invalid Position";
		return;
	}
	if(pos == 1)
	{
		this->addAtBeg(x);
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = new Node(x);
		q->next = p->next;
		p->next = q;
	}
}

void SLL::delAtBeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete ...empty list";
		return;
	}
	Node * p = head;
	head = head->next;
	delete p;
}

void SLL::delAtEnd()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete ...empty list";
		return;
	}
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}

void SLL::delByPos(int pos)
{
	int n = this->count();
	if(pos<1 || pos>n)
	{
		cout<<"\nInvalid Position";
		return;
	}
	if(pos == 1)
	{
		this->delAtBeg();
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

int main()
{
	SLL L;
	L.create();
	L.show();
	cout<<"\n\nTotal Nodes = "<<L.count();
	int x, pos;
	/*
	cout<<"\nEnter data to be searched : ";
	cin>>x;
	if(L.search(x))
		cout<<"\nFound";
	else
		cout<<"\nNot Found";
	*/
	
	
	return 0;
}
