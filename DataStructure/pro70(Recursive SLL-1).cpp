// Q. Define create(), show(), search() & count() recursively for SLL.

#include<iostream>
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
		
		Node* rec_create();
		void create();
		void rec_show(Node * p);
		void rec_show_rev(Node * p);
		void show();
		int rec_count(Node * p);
		int count();
		int rec_search(Node * p,int x);
		int search(int x);
};

Node* SLL::rec_create()
{
	int x;
	cout<<"\nEnter data or -1 to stop : ";
	cin>>x;
	if(x == -1)
	{
		return NULL;
	}
	Node * p = new Node(x);
	p->next = rec_create();
	return p;
}

void SLL::create()				//helper
{
	head = rec_create();
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

void SLL::show()				//helper
{
	cout<<"\n\nList in forward order :\n";
	rec_show(head);
	
	cout<<"\n\nList in reverse order :\n";
	rec_show_rev(head);
}

int SLL::rec_count(Node * p)
{
	if(p == NULL)
	{
		return 0;
	}
	return 1 + rec_count(p->next); 
}

int SLL::count()				//helper
{
	int i;
	i = rec_count(head);
	return i;
}

int SLL::rec_search(Node * p,int x)
{
	if(p == NULL)
	{
		return 0;					//Not Found
	}
	else if(p->data == x)
	{
		return 1;					//Found
	}
	else
	{
		return rec_search(p->next,x);
	}
}

int SLL::search(int x)				//helper
{
	return rec_search(head,x);
}

int main()
{
	SLL L;
	int x;

	cout<<"\nCreating List recursively\n";
	L.create();
	
	L.show();
	
	cout<<"\n\nTotal Nodes = "<<L.count();
	
	cout<<"\n\nEnter data to be searched : ";
	cin>>x;
	if(L.search(x))
	{
		cout<<"\nData Found";
	}
	else
	{
		cout<<"\nData Not Found";
	}
	return 0;
}


