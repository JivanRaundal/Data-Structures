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
	
	p = new Node(10);	//parameterized const will get called for runtime object
	q = new Node(20);
	r = new Node(30);
	
	//linking Nodes
	p->next = q;
	q->next = r;
	
	//printing data using p only
	cout<<"\np data = "<<p->data;
	cout<<"\nq data = "<<p->next->data;
	cout<<"\nr data = "<<p->next->next->data;
	
	
	delete(p);
	delete(q);
	delete(r);
	return 0;
}
