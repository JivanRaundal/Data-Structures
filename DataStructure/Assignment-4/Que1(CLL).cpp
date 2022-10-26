// Q 1]. CLL

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

class CLL
{
		Node * front;
		Node * rear;
	
	public:
		CLL()
		{
			front = rear = NULL;
		}
		void create();
		void show();
		void show_rec(Node * p);
		void help();
		int count();
		int search(int x);
		void addatbeg(int x);
		void addatend(int x);
		void addbypos(int pos,int x);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
		void makeEmpty();
};

void CLL::create()
{
	if(front != NULL)
	{
		cout<<"\nList Already Created...";
		return;
	}
	
	char str[10];
	cout<<"\nEnter first data or 'STOP' to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	front = new Node(atoi(str));
	front->next = front;
	rear = front;
	
	while(1)
	{
		cout<<"\nEnter next data or 'STOP' to stop : ";
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		rear->next = new Node(atoi(str));
		rear = rear->next;
		rear->next = front;
	}
}

void CLL::show()
{
	if(front==NULL)		//OR if(rear==NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	Node * p = front;
	do
	{
		cout<<" "<<p->data;
		p = p->next;
	}while(p != front);
}

int CLL::count()
{
	if(front==NULL)
	{
		return 0;
	}
	Node * p = front;
	int i=0;
	do
	{
		i++;
		p = p->next;
	}while(p != front);
	return i;
}

int CLL::search(int x)
{
	if(front==NULL)
	{
		cout<<"\nEmpty List";
		return 0;
	}
	Node * p = front;
	do
	{
		if(p->data == x)
		{
			return 1;
		}
		p = p->next;
	}while(p != front);
	return 0;
}

void CLL::show_rec(Node * p)
{
	if(p == rear)
	{
		cout<<" "<<p->data;
		return;
	}
	else
	{
		//cout<<" "<<p->data;
		show_rec(p->next);
		cout<<" "<<p->data;
	}
}

void CLL::help()
{
	cout<<"\n\nList in reverse order :\n";
	show_rec(front);
}

void CLL::addatbeg(int x)
{
	if(front == NULL)
	{
		front = new Node(x);
		front->next = front;
		rear = front;
	}
	else
	{
		Node * p;
		p = new Node(x);
		p->next = front;
		front = p;
		rear->next = front;
	}
}

void CLL::addatend(int x)
{
	if(front == NULL)
	{
		front = new Node(x);
		front->next = front;
		rear = front;
	}
	else
	{
		rear->next = new Node(x);
		rear = rear->next;
		rear->next = front;
	}
}

void CLL::addbypos(int pos,int x)
{
	int n;
	n = count();
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid Position";
		return;
	}
	cout<<"\nValid Position";
	if(pos == 1)
	{
		addatbeg(x);
	}
	else
	{
		Node * p = front;
		Node * q;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;	
		}
		q = new Node(x);
		q->next = p->next;
		p->next = q;
		if(pos == n+1)	//OR if(p==rear)
		{
			rear = q;
		}
	}
}

void CLL::delatbeg()
{
	if(front == NULL)
	{
		cout<<"\nCan't delete ...empty list";
		return;
	}
	
	if(front == rear)	//list contains only 1 node
	{
		delete front;
		front = rear = NULL;
	}
	else				//list contains multiple nodes
	{
		Node * p;
		p = front;
		front = front->next;
		rear->next = front;
		delete p;
	}
}

void CLL::delatend()
{
	if(front == NULL)
	{
		cout<<"\nCan't delete...empty list";
		return;
	}
	
	if(front == rear)	//list contains only 1 node
	{
		delete front;
		front = rear = NULL;
	}
	else				//list contains multiple nodes
	{
		Node * p = front;
		Node * q;
		while(p->next != front)		//OR while(p != rear)
		{
			q = p;
			p = p->next;
		}
		rear = q;
		rear->next = front;
		delete p;
	}
}

void CLL::delbypos(int pos)
{
	int n;
	n = count();
	if(pos < 1 || pos > n)
	{
		cout<<"\nInvalid Position";
		return;	
	}
	cout<<"\nValid Position";
	if(pos == 1)
	{
		delatbeg();
	}
	else
	{
		Node * p = front;
		Node * q;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		if(pos == n)	//OR if(q==rear)
		{
			rear = p;
		}
		delete q;
	}
}

void CLL::makeEmpty()
{
	if(front == NULL)
	{
		cout<<"\nList is empty";
		return;
	}
	Node * p = front;
	Node * q;
	do
	{
		q = front;
		front = front->next;
		delete q;
		//cout<<"\n-";
	}while(front != p);
	front = rear = NULL;
}

int main()
{
	CLL L;
	int pos,x,ch;
	
	do
	{
		cout<<"\n\n__________MENUE__________";
		cout<<"\n1.  create list";
		cout<<"\n2.  show list";
		cout<<"\n3.  show reverse list";
		cout<<"\n4.  count nodes";
		cout<<"\n5.  search data";
		cout<<"\n6.  add at beg";
		cout<<"\n7.  add at end";
		cout<<"\n8.  add by pos";
		cout<<"\n9.  del at beg";
		cout<<"\n10.  del at end";
		cout<<"\n11. del by pos";
		cout<<"\n12. make list empty";
		cout<<"\n13. exit";
		cout<<"\n_________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				L.create();
				break;
				
			case 2:
				cout<<"\nLIST :\n";
				L.show();
				break;
				
			case 3:
				L.help();
				break;
				
			case 4:
				cout<<"\nTotal Nodes = "<<L.count();
				break;
				
			case 5:
				cout<<"\nEnter data to be searched : ";
				cin>>x;
				if(L.search(x))
				{
					cout<<"\nData Found";
				}
				else
				{
					cout<<"\nData Not Found";
				}
				break;
				
			case 6:
				cout<<"\nEnter data to add at beg : ";
				cin>>x;
				L.addatbeg(x);
				break;
				
			case 7:
				cout<<"\nEnter data to add at end : ";
				cin>>x;
				L.addatend(x);
				break;
				
			case 8:
				cout<<"\nEnter position & data : ";
				cin>>pos>>x;
				L.addbypos(pos,x);
				break;
				
			case 9:
				L.delatbeg();
				break;
				
			case 10:
				L.delatend();
				break;
				
			case 11:
				cout<<"\nEnter position of data to be deleted : ";
				cin>>pos;
				L.delbypos(pos);
				break;
				
			case 12:
				L.makeEmpty();
				break;
				
			case 13:
				exit(0);
				
			default:
				cout<<"\nInvali Choice...Plz try again!!!";
		}
		
	}while(ch != 13);
	
	return 0;
}
