// Q 15]. Scan a number from user & store it's binary in 8 bits using DLL. Print binary.

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *prev, *next;
		
		Node()
		{
			data = 0;
			prev = next = NULL;
		}
		Node(int x)
		{
			data = x;
			prev = next = NULL;
		}
};

class DLL
{
		Node * head;
	
	public:
		DLL()
		{
			head = NULL;
		}
		
		void addatend(int x)
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
				p->next->prev = p;
			}
		}
		
		void show_rev()
		{
			if(head == NULL)
			{
				cout<<"\nList Empty";
				return;
			}
			else
			{
				Node * p = head;
				while(p->next != NULL)
				{
					p = p->next;
				}
				while(p != NULL)
				{
					cout<<p->data;
					p = p->prev;
				}
			}
		}
};

int main()
{
	DLL L;
	int num;
	
	cout<<"\nEnter a number : ";
	cin>>num;
	
	int i=1;
	while(i<=8)
	{
		L.addatend(num%2);
		num = num/2;
		i++;
	}
	
	cout<<"\n\n8 bits binary of number = ";
	L.show_rev();
	
	return 0;
}
