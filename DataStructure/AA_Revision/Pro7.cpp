//Creating simple linked list

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
	int n,x;
	cout<<"\nHow many elements : ";
	cin>>n;
	
	Node * p = NULL;
	Node * head = NULL;
	
	cout<<"\nEnter first element : ";
	cin>>x;
	p = new Node(x);
	head = p;
	
	for(int i=1; i<=n-1; i++)
	{
		cout<<"\nEnter element : ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;
	}
	
	cout<<"\n\nPrinting Linked List :\n";
	p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
	
	return 0;
}
