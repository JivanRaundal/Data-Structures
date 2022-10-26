// Reversing a linked list

#include<bits/stdc++.h>
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

class SLL
{
	private:
		Node * head;
	public:
		SLL()
		{
			head = NULL;
		}
		
		void addAtEnd(int x);
		void show();
		void reverseList();
		void rec_rev_list();
		Node* rec_rev_list_util(Node * p);
};

void SLL::addAtEnd(int x)
{
	if(head == NULL)
	{
		head = new Node(x);
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

void SLL::show()
{
	cout<<"\nLIST :\n";
	Node * p = head;
	while(p != NULL)
	{
		cout<<p->data<<" -> ";
		p = p->next;
	}
	cout<<"NULL";
}

void SLL::reverseList()
{
	if(head == NULL)
	{
		return;
	}
	Node * prevptr = NULL;
	Node * currptr = head;
	Node * nextptr = NULL;
	
	while(currptr != NULL)
	{
		nextptr = currptr->next;
		currptr->next = prevptr;
		
		prevptr = currptr;
		currptr = nextptr;
	}
	head = prevptr;
}

void SLL::rec_rev_list()
{
	if(head == NULL)
	{
		return;
	}
	rec_rev_list_util(head);
}

Node* SLL::rec_rev_list_util(Node* p)
{
	if(p==NULL || p->next == NULL)
	{
		head = p;
		return p;
	}

		Node * prev = rec_rev_list_util(p->next);
		prev->next = p;
		p->next = NULL;
		return p;
}

int main()
{
	SLL lst;
	
	int n,x;
	cout<<"\nHow many nodes : ";
	cin>>n;
	
	cout<<"\nEnter list elements\n";
	for(int i=0; i<n; i++)
	{
		cin>>x;
		lst.addAtEnd(x);
	}
	
	lst.show();
	
	lst.reverseList();
	
	cout<<"\n\nAfter Reversing Linked List\n";
	lst.show();
	
	lst.rec_rev_list();
	lst.show();
	
	return 0;
}
