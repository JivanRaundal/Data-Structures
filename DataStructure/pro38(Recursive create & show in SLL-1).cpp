//	Recursive Create & show Function for SLL

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
		
		Node* create();
		void rec_show(Node * p);
		void help();
};

Node* SLL::create()
{
	char str[10];
	cout<<"\nEnter data or 'STOP' to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return NULL;
	}
	Node * p;
	p = new Node(atoi(str));
	p->next = create();
	return p;
}

void SLL::rec_show(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	cout<<" "<<p->data;
	rec_show(p->next);
}

void SLL::help()
{
	cout<<"\nCreating List : ";
	head = create();	//recursive create will call
	cout<<"\n\nList :\n";
	rec_show(head);
}

int main()
{
	SLL L;
	L.help();
	return 0;
}
