// SLL

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
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
		void concat(SLL T);
};

void SLL::create()
{
	char str[30];
	cout<<"\nEnter data or STOP to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;	
	}
	head = new Node(atoi(str));
	Node * p = head;
	while(1)
	{
		cout<<"\nEnter data or STOP to stop : ";
		cin>>str;
		if(strcmp(str, "STOP") == 0)
		{
			break;
		}
		addAtEnd(atoi(str));
		//p->next = new Node(atoi(str));
		//p = p->next;
	}
}

void SLL::show()
{
	cout<<"\n\nLIST :\n";
	if(head == NULL)
	{
		cout<<"Empty List";
	}
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

int SLL::count()
{
	if(head == NULL)
	{
		return 0;
	}
	Node * p = head;
	int count=0;
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
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = new Node(x);
}

void SLL::addByPos(int pos,int x)
{
	int n = count();
	if(pos<1 || pos>n+1)
	{
		cout<<"\nInvalid Position";
		return;
	}
	if(pos == 1)
	{
		addAtBeg(x);
	}
	else
	{
		Node * p = head;
		Node * temp = NULL;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		temp = new Node(x);
		temp->next = p->next;
		p->next = temp;
	}
}

void SLL::delAtBeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete";
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
		cout<<"\nCan't delete";
		return;
	}
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

void SLL::concat(SLL T)
{
	if(head==NULL)
	{
		cout<<"\nCan't concat";
		return;
	}
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = T.head;
}

int main()
{
	SLL L;
	SLL L2;
	int pos,x;
	
	L.create();
	L.show();
	
	/*cout<<"\n\nTotal nodes = "<<L.count();
	cout<<"\n\nEnter data to search : ";
	cin>>x;
	if(L.search(x))
		cout<<"\nFound";
	else
		cout<<"\nNot Found";
	
	L.addAtBeg(2);
	L.addAtBeg(4);
	L.show();
	L.addAtEnd(90);
	L.addAtEnd(100);
	L.show();
	
	cout<<"\n\nEnter Postion & data : ";
	cin>>pos>>x;
	L.addByPos(pos, x);
	L.show();
	cout<<"\n\nEnter Postion & data : ";
	cin>>pos>>x;
	L.addByPos(pos, x);
	L.show();
	cout<<"\n\nEnter Postion & data : ";
	cin>>pos>>x;
	L.addByPos(pos, x);
	L.show();
	
	L.delAtBeg();
	L.show();
	L.delAtEnd();
	L.show();
	
	cout<<"\nEnter Position to be deleted : ";
	cin>>pos;
	L.delByPos(pos);
	L.show();
	cout<<"\nEnter Position to be deleted : ";
	cin>>pos;
	L.delByPos(pos);
	L.show();
	cout<<"\nEnter Position to be deleted : ";
	cin>>pos;
	L.delByPos(pos);
	L.show();
	*/
	
	cout<<"\n\nCreating Second List";
	L2.create();
	cout<<"\nPrinting Second List";
	L2.show();
	
	L.concat(L2);
	cout<<"\n\nAfter Concatenating";
	L.show();
	
	return 0;
}
