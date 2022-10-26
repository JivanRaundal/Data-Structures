#include<iostream>
#include<stdlib.h>
#include<string.h>
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
		
		void create();
		void show();
		int count();
		int average();
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList ALready Created";
		return;
	}
	char str[20];
	int x;
	cout<<"\nEnter first data or STOP to stop : ";
	cin>>str;
	if(strcmp(str, "STOP") == 0)
	{
		return;
	}
	x = atoi(str);
	head = new Node(x);
	Node * p = head;
	while(1)
	{
		cout<<"\nEnter next data or STOP to stop : ";
		cin>>str;
		if(strcmp(str, "STOP") == 0)
		{
			break;
		}
		x = atoi(str);
		p->next = new Node(x);
		p = p->next;
	}
	cout<<"\nList Created";
}

void SLL::show()
{
	cout<<"\n\nLIST :\n";
	if(head == NULL)
	{
		cout<<"Empty List";
	}
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

int SLL::count()
{
	if(head == NULL)
	{
		return 0;
	}
	int count=0;
	Node * p = head;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int SLL::average()
{
	if(head == NULL)
	{
		return 0;
	}
	int avg = 0;
	int n = this->count();
	Node * p = head;
	while(p != NULL)
	{
		avg = avg + p->data;
		p = p->next;
	}
	avg = avg / n;
	return avg;
}

int main()
{
	SLL L1, L2;
	cout<<"\nEnter data for first List\n\n";
	L1.create();
	cout<<"\n\nEnter data for second List\n\n";
	L2.create();
	cout<<"\n\nAverage of first list = "<<L1.average();
	cout<<"\n\nAverage of second list = "<<L2.average();
	if(L1.average() > L2.average())
	{
		L1.show();
	}
	else
	{
		L2.show();
	}
	
	return 0;
}


