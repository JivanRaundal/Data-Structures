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
		
		//void create()
		void addatbeg(int x);
		void show();
};

void SLL::show()
{
	Node * p = head;
	while(p != NULL)
	{
		cout<<p->data;
		p = p->next;
	}
}

void SLL::addatbeg(int x)
{
	if(head == NULL)
	{
		head = new Node(x);
	}
	else
	{
		Node * p;
		p = new Node(x);
		p->next = head;
		head = p;
	}
}

int main()
{
	SLL binary;
	
	int n;
	cout<<"\nEnter Number : ";
	cin>>n;
	for(int i=1; i<=16; i++)
	{
		binary.addatbeg(n%2);	//for binary conversion 2
		n = n/2;
	}
	cout<<"\nBinary of given number is = ";
	binary.show();
	return 0;
}
