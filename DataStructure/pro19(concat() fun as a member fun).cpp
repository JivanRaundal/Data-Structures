// Q. complete the code for given main() function.
// Note => To convert string into integer we have to use 'atoi()' function and all the characters in the string must
//		   be numbers.	SYNTAX - atoi(base_addr_of_str);	-> It returns an integer

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class SLL;	//forward declaration
class Node
{
	private:
		int data;
		Node * next;
	
	public:
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
		
		friend class SLL;
		friend void show(SLL T);
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
		void concat(SLL T);
		
		friend void show(SLL T);
};

void SLL::create()
{
	char str[100];
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
}

void SLL::show()		
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
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

void SLL::concat(SLL T)
{
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	// p will refer to last node
	p->next = T.head;
}

void show(SLL T)		//Independent show() function
{
	if(T.head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	else
	{
		Node * p = T.head;
		while(p != NULL)
		{
			cout<<" "<<p->data;
			p = p->next;
		}
	}
}

int main()
{
	SLL L1,L2;
	
	cout<<"\nEnter List 1 data";
	L1.create();
	cout<<"\nEnter List 2 data";
	L2.create();
	L1.concat(L2);
	cout<<"\nLIST 1 :\n";
	show(L1);
	cout<<"\nLIST 2 :\n";
	L2.show();
	
	return 0;
}

