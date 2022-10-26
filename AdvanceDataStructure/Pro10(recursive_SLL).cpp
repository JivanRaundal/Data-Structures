// Recursive SLL

#include<iostream>
#include<stdlib.h>
#include<String.h>
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
		
		void create()
		{
			head = rec_create();
		}
		
		Node* rec_create()
		{
			char str[10];
			cout<<"\nEnter data or STOP to stop : ";
			cin>>str;
			if(strcmp(str, "STOP") == 0)
			{
				return NULL;
			}
			Node * p;
			p = new Node(atoi(str));
			p->next = rec_create();
			return p;
		}
		
		void show()
		{
			cout<<"\n\nPrinting list in forward direction\n";
			rec_show(head);
			cout<<"\n\nPrinting list in reverse direction\n";
			rec_showrev(head);
		}
		
		void rec_show(Node * p)
		{
			if(p == NULL)
			{
				return;
			}
			else
			{
				cout<<"  "<<p->data;
				rec_show(p->next);
			}
		}
		
		void rec_showrev(Node * p)
		{
			if(p == NULL)
			{
				return;
			}
			else
			{
				rec_showrev(p->next);
				cout<<"  "<<p->data;
			}
		}
		
		void count()
		{
			cout<<"\n\nTotal Nodes = "<<rec_count(head);
		}
		
		int rec_count(Node * p)
		{
			if(p == NULL)
			{
				return 0;
			}
			else
			{
				return 1 + rec_count(p->next);
			}
		}
		
		int search(int x)
		{
			return rec_search(head, x);
		}
		
		int rec_search(Node * p,int x)
		{
			if(p == NULL)
			{
				return 0;
			}
			if(p->data == x)
			{
				return 1;
			}
			else
			{
				return rec_search(p->next, x);
			}
		}
};

int main()
{
	SLL L;
	L.create();
	L.show();
	L.count();
	int x;
	cout<<"\n\nEnter data to be search : ";
	cin>>x;
	if(L.search(x))
	{
		cout<<"\nFound";
	}
	else
	{
		cout<<"\nNot Found";
	}
	
	return 0;
}


