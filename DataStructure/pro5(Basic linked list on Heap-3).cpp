//			LINKED LIST
// # Basic linked list on Heap (as per college) :-
// eg-

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		
		Node()		//default constructor
		{
			next = NULL;
		}
		Node(int x)		//parameterized constructor
		{
			data = x;
			next = NULL;
		}
};

int main()
{
	Node *p,*q,*r;		//pointers to object OR pointer var of type Node
	
	p = new Node();	//default const will get called for runtime object
	q = new Node();
	r = new Node();
	
	//linking Nodes
	Node * head;
	head = p;
	head->next = q;
	head->next->next = r;
	
	cout<<"\nScanning Linked List :\n";
	Node * temp = head;
	while(temp != NULL)
	{
		cout<<"\nEnter data : ";
		cin>>temp->data;
		temp = temp->next;
	}
	
	cout<<"\n\nprinting Linked List :\n";
	temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	delete(p);
	delete(q);
	delete(r);
	return 0;
}
