// Q 13]. diagram-3)

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
	Node *p,*q,*r;
	
	p = new Node(10);
	q = new Node(20);
	r = new Node(30);
	
	p->next = q;
	q->next = r;
	
	cout<<"\nList :\n";
	cout<<" "<<p->data;
	cout<<" "<<p->next->data;
	cout<<" "<<p->next->next->data;
	
	delete p;
	delete q;
	delete r;
	return 0;
}
