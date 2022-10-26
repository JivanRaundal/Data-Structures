 // Q 11].

#include<iostream>
using namespace std;

class SLL;	//forward declaration
class Node
{
	private:
		int data;
		Node * next;
		
	public:
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
		
		friend class SLL;
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
		cout<<"\nList already created";
		return;
	}
	
	Node * p = NULL;
	int n,x,i;
	cout<<"\nHow many nodes? ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid number";
		return;
	}
	
	cout<<"\nEnter first node data : ";
	cin>>x;
	head = new Node(x);
	p = head;
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next node data : ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;
	}
}

void SLL::show()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
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
	int i=0;
	Node * p = head;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int SLL::average()
{
	if(head == NULL)
	{
		cout<<"\nCan't find average. List is empty";
		return 0;
	}
	
	Node * p = head;
	int n,avg, sum = 0;
	n = count();	//total number of nodes
	
	while(p != NULL)
	{
		sum = sum + p->data;
		p = p->next;
	}
	avg = sum/n;
	return avg;
}

int main()
{
	SLL L1,L2;
	
	cout<<"\nCreate first list :";
	L1.create();
	
	cout<<"\nCreate second list :";
	L2.create();
	
	cout<<"\n\nList With greater average :\n";
	
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

