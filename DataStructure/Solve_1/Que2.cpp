// Q 2]. 

#include<iostream>
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
		void show();
		int add();
		
		friend int rec_add(SLL T);
};

void SLL::create()
{
	Node * p = NULL;
	int n,x,i;
	cout<<"\nHow many nodes? ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid Number";
		return;
	}
	
	cout<<"\nEnter first data : ";
	cin>>x;
	head = new Node(x);
	
	p = head;
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next data : ";
		cin>>x;
		
		p->next = new Node(x);
		p = p->next;
	}
}

void SLL::show()
{
	if(head == NULL)
	{
		cout<<"\nEmpty list";
		return;
	}
	
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

int SLL::add()		//Non-recursive
{
	Node * p = head;
	int sum = 0;
	while(p != NULL)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return sum;
}

int rec_add(SLL T)		//recursive  Note :- we can change head of T here
{
	if(T.head == NULL)
	{
		return 0;
	}
	int x = T.head->data;
	T.head = T.head->next;
	return x + rec_add(T);
}

int main()
{
	SLL S;
	
	S.create();
	cout<<"\n\nLIST :\n";
	S.show();
	
	cout<<"\n\nNon-recursive Addition = "<<S.add();
	
	cout<<"\n\nRecursive Addition = "<<rec_add(S);
	
	return 0;
}
