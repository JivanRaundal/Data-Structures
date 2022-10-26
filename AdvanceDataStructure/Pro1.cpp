// Tree Class Node

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
		Node()
		{
			data = 0;
			left = right = NULL;
		}
		Node(int x)
		{
			data = x;
			left = right = NULL;
		}
};

int main()
{
	Node *p,*q,*r;
	p = new Node(10);
	q = new Node(20);
	r = new Node(30);
	
	p->left = q;
	p->right = r;
	
	cout<<"\nPrinting data using p \n";
	cout<<"  "<<p->data;
	cout<<"  "<<p->left->data;
	cout<<"  "<<p->right->data;
	
	return 0;
}
