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
};

int main()
{
	Node *p,*q,*r;		//pointers to object
	
	p = new Node();
	p->data = 10;
	p->next = NULL;
	
	q = new Node();
	q->data = 20;
	q->next = NULL;
	
	r = new Node();
	r->data = 30;
	r->next = NULL;
	
	//linking Nodes
	p->next = q;
	q->next = r;
	
	//printing linked list on heap using p only
	cout<<"\np data = "<<p->data;
	cout<<"\nq data = "<<p->next->data;
	cout<<"\nr data = "<<p->next->next->data;
	
	delete(p);
	delete(q);
	delete(r);
	return 0;
}

