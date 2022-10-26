// Linked List

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

int main()
{
	Node *p;
	
	p  			 	    = new Node(10);
	p->next  	  	    = new Node(20);
	p->next->next 	    = new Node(30);
	p->next->next->next = new Node(40);
	
	cout<<"\np->data = "<<p->data;
	cout<<"\np->next->data = "<<p->next->data;
	cout<<"\np->next->next->data = "<<p->next->next->data;
	cout<<"\np->next->next->next->data = "<<p->next->next->next->data;
	
	delete p;
	return 0;	
}

