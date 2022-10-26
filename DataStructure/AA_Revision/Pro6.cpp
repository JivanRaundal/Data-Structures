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
	Node *p, *q, *r;
	p = new Node(10);
	q = new Node(20);
	r = new Node(30);
	
	p->next = q;
	q->next = r;
	r->next = NULL;
	
	cout<<" "<<p->data<<" "<<p->next->data<<" "<<p->next->next->data;
	return 0;
}
