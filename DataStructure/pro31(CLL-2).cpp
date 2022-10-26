// CLL

#include<iostream>
#include<string.h>
#include<stdlib.h>
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
	private:
		Node * front;
		Node * rear;
	
	public:
		CLL()
		{
			front = rear = NULL;
		}
		
		void create();
		void show();
		int count();
		int search(int x);
		void addatbeg(int x);
		void addatend(int x);
		void addbypos(int pos,int x);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
};

void CLL::create()
{
	if(front != NULL)
	{
		cout<<"\nList Already Exists";
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
		addatend(atoi(str));
	}
	cout<<"\nList Created Successfully";
}

void CLL::show()
{
	if(front == NULL)
	{
		cout<<"\nList Is Empty";
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
	if(front == NULL)
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
	if(front == NULL)
	{
		cout<<"\nCan't search...List is empty";
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
		Node * p = new Node(x);
		p->next = front;
		rear->next = p;
		front = p;
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
	int n = count();
	//check position is valid or not
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
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;
		}
		q = new Node(x);
		q->next = p->next;
		p->next = q;
		
		if(pos == n+1)	//if position is n+1, then only rear will change
		{
			rear = q;
		}
	}
}

void CLL::delatbeg()
{
	if(front == NULL)
	{
		cout<<"\nCan't delete...Empty list";
		return;
	}
	if(front == rear)	//i.e. if list contains only 1 node
	{
		delete front;
		front = rear = NULL;
	}
	else
	{
		Node * p = front;
		front = front->next;
		rear->next = front;
		delete p;
	}
}

void CLL::delatend()
{
	if(front == NULL)
	{
		cout<<"\nCan't delete...List empty";
		return;
	}
	if(front == rear)	//if list contains only 1 node
	{
		delete front;
		front = rear = NULL;
	}
	else
	{
		Node * p = front;
		Node * q;
		while(p->next != front)		//while(p != rear)
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
	int n = count();
	//check valid position
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
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		if(pos == n)	//if pos == n, then only rear will change
		{
			rear = p;
		}
		delete q;	//delete at last
	}
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
		cout<<"\n3.  count nodes";
		cout<<"\n4.  search data";
		cout<<"\n5.  add at beg";
		cout<<"\n6.  add at end";
		cout<<"\n7.  add by pos";
		cout<<"\n8.  del at beg";
		cout<<"\n9.  del at end";
		cout<<"\n10. del by pos";
		cout<<"\n11. exit";
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
				cout<<"\nTotal Nodes = "<<L.count();
				break;
				
			case 4:
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
				
			case 5:
				cout<<"\nEnter data to add at beg : ";
				cin>>x;
				L.addatbeg(x);
				break;
				
			case 6:
				cout<<"\nEnter data to add at end : ";
				cin>>x;
				L.addatend(x);
				break;
				
			case 7:
				cout<<"\nEnter position & data : ";
				cin>>pos>>x;
				L.addbypos(pos,x);
				break;
				
			case 8:
				L.delatbeg();
				break;
				
			case 9:
				L.delatend();
				break;
				
			case 10:
				cout<<"\nEnter position of data to be deleted : ";
				cin>>pos;
				L.delbypos(pos);
				break;
				
			case 11:
				exit(0);
				
			default:
				cout<<"\nInvali Choice...Plz try again!!!";
		}
		
	}while(ch != 11);
	
	return 0;
}
