// Basic GLL(Generalized Linked List)

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node
{
	public:
		union Share
		{
			int data;
			Node * subhead;
		};
		Share S;
		int flag;
		Node * next;
		
		Node()
		{
			//S.data = 0;
			flag = -1;
			next = NULL;
			S.subhead = NULL;
		}
		Node(int x)
		{
			S.data = x;
			flag = -1;
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
		
		Node* create_gll();
		void show_gll(Node * p);
		void help();
};

Node* SLL::create_gll()
{
	char ch;
	Node *p = NULL;
	char str[10];
	
	cout<<"\nDo you want to add sublist in this node? (y/n)? ";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
	{
		cout<<"\nCreating Sublist -----------";
		p = new Node();		//default const will call
		p->flag = 0;		//bcz we are adding sublist here
		p->S.subhead = create_gll();
		cout<<"\nSublist ended here----------";
		cout<<"\nDo you want to continue main list? (y/n)? ";
		cin>>ch;
		if(ch == 'y' || ch == 'Y')
		{
			p->next = create_gll();
		}
		return p;
	}
	
	cout<<"\nEnter data or 'STOP' to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return NULL;
	}
	p = new Node(atoi(str));
	p->flag = 1;	//bcz we are adding data
	p->next = create_gll();
	return p;
}

void SLL::show_gll(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	if(p->flag == 0)
	{
		cout<<" (";
		show_gll(p->S.subhead);
		cout<<" )";
		p = p->next;	
	}
	if(p->flag == 1)		//i.e.  if(p->flag == 1)
	{
		cout<<" "<<p->S.data<<",";
		show_gll(p->next);
	}
} 

void SLL::help()
{
	cout<<"\nCreating GLL : ";
	head = create_gll();
	
	cout<<"\n\nPrinting GLL :\n";
	cout<<"[ ";
	show_gll(head);
	cout<<" ]";
}

int main()
{
	SLL L;
	L.help();
	return 0;
}
