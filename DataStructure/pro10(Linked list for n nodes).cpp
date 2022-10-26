// Q. Ask user that how many nodes he/she want in list

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
			next =NULL;
		}
};

int main()
{
	Node *p = NULL;
	Node *head = NULL;
	
	int n,x,i;
	cout<<"\nHow many nodes you want? ";
	cin>>n;
	
	//Note - Always create head node first outside loop & then n-1 nodes using loop
	cout<<"\n\nEnter data of first node : ";
	cin>>x;
	head = new Node(x);
	p = head;
	
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter data of next node : ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;	
	}
	
	cout<<"\n\nList :\n";
	p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
	
	delete head;
	delete p;
	return 0;
}
