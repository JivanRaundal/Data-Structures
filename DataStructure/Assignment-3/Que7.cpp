// Q 7].

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
		void merge(SLL T1,SLL T2);
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Already Created...";
		return;
	}
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
	cout<<"\nList created successfully";
};

void SLL::show()
{
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

void SLL::merge(SLL T1,SLL T2)
{
	Node * p = T1.head;
	Node * q = T2.head;
	
	while(p != NULL  &&  q != NULL)
	{
		if(p->data < q->data)
		{
			this->addatend(p->data);
			p = p->next;
		}
		else
		{
			this->addatend(q->data);
			q = q->next;
		}
	}
	
	while(p != NULL)
	{
		addatend(p->data);
		p = p->next;
	}
	
	while(q != NULL)
	{
		addatend(q->data);
		q = q->next;
	}
	
	cout<<"\n\nLists are Merged Successfully";
}

int main()
{
	SLL L1,L2,Target;
	
	cout<<"\n\nCreating List 1 :";
	L1.create();
	cout<<"\n\nList 1 before sorting:\n";
	L1.show();
	L1.sort();
	cout<<"\n\nList 1 after sorting :\n";
	L1.show();
	
	cout<<"\n\nCreating List 2 :";
	L2.create();
	cout<<"\n\nList 2 before sorting:\n";
	L2.show();
	L2.sort();
	cout<<"\n\nList 2 after sorting :\n";
	L2.show();
	
	Target.merge(L1,L2);
	cout<<"\n\nTarget List :\n";
	Target.show();
	
	return 0;
}
