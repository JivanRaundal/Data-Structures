// SLL

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
		int search(int x);
		void addAtBeg(int x);
		void addAtEnd(int x);
		void addByPos(int pos,int x);
		void delAtBeg();
		void delAtEnd();
		void delByPos(int pos);
		void concat(SLL T);
		
		friend void show(SLL L);
};

void SLL::create()
{
	int n,x,i;
	Node * p = NULL;
	cout<<"\nHow many nodes ? ";
	cin>>n;
	cout<<"\nEnter data for first node : ";
	cin>>x;
	head = new Node(x);
	p = head;
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter data : ";
		cin>>x;
		p->next = new Node(x);
		p = p->next;
	}
	cout<<"\nList Created Successfully";
}

void SLL::show()
{
	cout<<"\n\nLIST :\n";
	if(head == NULL)
	{
		cout<<"Empty";
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

int SLL::search(int x)
{
	if(head == NULL)
	{
		return 0;
	}
	Node * p = head;
	while(p != NULL)
	{
		if(p->data == x)			
		{
			return 1;		//Found
		}
		p = p->next;
	}
	return 0;				//Not Found
}

void SLL::addAtBeg(int x)
{
	Node * p = new Node(x);
	p->next = head;
	head = p;
}

void SLL::addAtEnd(int x)
{
	if(head == NULL)
	{
		head = new Node(x);
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)			//will stop on last node
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

void SLL::addByPos(int pos,int x)
{
	int n = count();
	if(pos<1 || pos>n+1)
	{
		cout<<"\nInvalid Position";
		return;
	}
	if(pos == 1)
	{
		addAtBeg(x);
	}
	else
	{
		Node * p = head;
		Node * temp = NULL;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		temp = new Node(x);
		temp->next = p->next;
		p->next = temp;
	}
}

void SLL::delAtBeg()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	Node * p = head;
	head = head->next;
	delete p;
}

void SLL::delAtEnd()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	Node * p = head;
	Node * q = NULL;
	while(p->next != NULL)
	{
		q = p;
		p = p->next;
	}
	q->next = NULL;
	delete p;
}

void SLL::delByPos(int pos)
{
	int n = count();
	if(pos<1 || pos>n)
	{
		cout<<"\nInvalid Position";
		return;
	}
	if(pos == 1)
	{
		delAtBeg();
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

void SLL::concat(SLL T)			//List passed as a para will be concatenated with calling List 
{
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = T.head;
}

//Printing list using non-member function
void show(SLL L)
{
	if(L.head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	cout<<"\n\nPrinting Using Independent function show() :\n";
	Node * p = L.head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

int main()
{
	SLL L;
	SLL L2;
	int x,pos;
	
	L.create();
	L.show();
	show(L);
	/*cout<<"\n\nTotal Nodes in List = "<<L.count();
	cout<<"\n\nEnter element to be searched : ";
	cin>>x;
	if(L.search(x))
	{
		cout<<"\nFound";
	}
	else
	{
		cout<<"\nNot Found";
	}
	
	cout<<"\n\nEnter data to add at beg : ";
	cin>>x;
	L.addAtBeg(x);
	L.show();
	cout<<"\n\nEnter data to add at end : ";
	cin>>x;
	L.addAtEnd(x);
	L.show();
	
	cout<<"\n\nEnter Position & data : ";
	cin>>pos>>x;
	L.addByPos(pos, x);
	L.show();
	cout<<"\nEnter Position & data : ";
	cin>>pos>>x;
	L.addByPos(pos, x);
	L.show();
	cout<<"\nEnter Position & data : ";
	cin>>pos>>x;
	L.addByPos(pos, x);
	L.show();
	
	L.delAtBeg();
	L.show();
	L.delAtEnd();
	L.show();
	
	cout<<"\n\nEnter Position to be deleted : ";
	cin>>pos;
	L.delByPos(pos);
	L.show();
	cout<<"\n\nEnter Position to be deleted : ";
	cin>>pos;
	L.delByPos(pos);
	L.show();
	cout<<"\n\nEnter Position to be deleted : ";
	cin>>pos;
	L.delByPos(pos);
	L.show();
	
	cout<<"\n\nCreating second list \n";
	L2.create();
	cout<<"\n\nSecond List :\n";
	L2.show();
	
	L.concat(L2);
	cout<<"\n\nAfter Concatenating List is :\n";
	L.show();
	*/
	
	return 0;
}
