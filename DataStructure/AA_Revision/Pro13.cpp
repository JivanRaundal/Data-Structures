// Printing SLL using recursion

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
		
		void create()
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
				//addAtEnd(atoi(str));
				p->next = new Node(atoi(str));
				p = p->next;
			}
		}
		Node* getHead()				//will return head pointer as it is private
		{
			return head;
		}
};

void show(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	else
	{
		cout<<" "<<p->data;
		show(p->next);
	}
}

void revShow(Node * p)
{
	if(p == NULL)
	{
		return;
	}
	else
	{
		revShow(p->next);
		cout<<" "<<p->data;
	}
}

int main()
{
	SLL L;
	L.create();
	cout<<"\n\nPrinting List using recursion";
	cout<<"\n\nForward\n";
	show(L.getHead());
	cout<<"\n\nReverse\n";
	revShow(L.getHead());
	return 0;
}
