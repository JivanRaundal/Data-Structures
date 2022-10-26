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
	Node * p = NULL;
	Node * head = NULL;
	
	p = new Node(10);
	head = p;
	
	p->next = new Node(20);
	p = p->next;
	p->next = new Node(30);
	p = p->next;
	p->next = new Node(40);
	p = p->next;
	
	//printing using loop
	p = head;
	cout<<"\nList :\n";
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
	
	delete p;
	delete head;
	return 0;
}
