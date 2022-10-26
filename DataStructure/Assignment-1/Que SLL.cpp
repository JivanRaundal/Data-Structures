//	SLL

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

class SLL
{
		Node * head;
	public:
		SLL()
		{
			head = NULL;
		}
		void create();
		void show();
		int count();
		int search(int);
		void addatbeg(int);
};

void SLL::create()
{
	Node * p;
	int n,x,i;
	cout<<"\nHow many nodes : ";
	cin>>n;
	cout<<"\nEnter first node data : ";
	cin>>x;
	head = new Node(x);
	p = head;
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next data : ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;
	}
}

void SLL::show()
{
	cout<<"\n";
	Node * p;
	p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

int SLL::count()
{
	Node * p = head;
	int i = 0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int SLL::search(int x)
{
	Node * p = head;
	while(p != NULL)
	{
		if(p->data == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void SLL::addatbeg(int x)
{
	Node * p;
	p = new Node(x);
	p->next = head;
	head = p;
}

int main()
{
	SLL obj;
	
	//obj.create();
	cout<<"\nList = ";
	obj.show();
	
	cout<<"\nTotal Nodes = "<<obj.count();
	
	int x;
	cout<<"\nEnter data to be searched : ";
	cin>>x;
	if(obj.search(x))
	{
		cout<<"\nData Found";
	}
	else
	{
		cout<<"\nData Not Found";
	}
	
	cout<<"\nEnter Data to be add at the beginning : ";
	cin>>x;
	obj.addatbeg(x);
	cout<<"\nList = ";
	obj.show();
	
	cout<<"\nEnter Data to be add at the beginning : ";
	cin>>x;
	obj.addatbeg(x);
	cout<<"\nList = ";
	obj.show();
	
	cout<<"\nTotal = "<<obj.count();
	
	return 0;
}
