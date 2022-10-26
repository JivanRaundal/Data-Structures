//	DCLL

#include<iostream>
#include<string.h>
#include<stdlib.h>
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

class DCLL
{
	private:
		Node *front, *rear;
	
	public:
		DCLL()
		{
			front = rear = NULL;
		}
		
		void create();
		void show();
		void rev_show();
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

void DCLL::create()
{
	if(front != NULL)
	{
		cout<<"\nList Already Created";
		return;
	}
	
	int n,x,i;
	cout<<"\nHow many nodes? ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid Number";
		return;
	}
	cout<<"\nEnter first data : ";
	cin>>x;
	front = new Node(x);
	front->next = front;
	front->prev = front;
	rear = front;
	
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next data : ";
		cin>>x;
		rear->next = new Node(x);
		rear->next->prev = rear;
		rear = rear->next;
		rear->next = front;
		front->prev = rear;
	}
	cout<<"\nList Created Successfully";
}

void DCLL::show()
{
	if(front == NULL)
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

void DCLL::rev_show()
{
	if(front == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	//Node * p = front;
	/*while(p->next != front)		//OR while(p != rear)
	{
		p = p->next;		//p will refer last node i.e. rear
	}*/
	Node * p = rear;
	do
	{
		cout<<" "<<p->data;
		p = p->prev;
	}while(p != rear);
}

int DCLL::count()
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

int DCLL::search(int x)
{
	if(front == NULL)
	{
		cout<<"\ncan't search...empty list";
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

void DCLL::addatbeg(int x)
{
	if(front == NULL)
	{
		front = new Node(x);
		front->next = front;
		front->prev = front;
		rear = front;
	}
	else
	{
		front->prev = new Node(x);
		front->prev->next = front;
		front = front->prev;
		front->prev = rear;
		rear->next = front;
	}
}

void DCLL::addatend(int x)
{
	if(front == NULL)
	{
		front = new Node(x);
		front->next = front;
		front->prev = front;
		rear = front;
	}
	else
	{
		rear->next = new Node(x);
		rear->next->prev = rear;
		rear = rear->next;
		rear->next = front;
		front->prev = rear;
	}
}

void DCLL::delatbeg()
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
	else				//list contains more than 1 nodes
	{
		front = front->next;
		delete front->prev;		//Note- try with using extra pointer also
		front->prev = rear;
		rear->next = front;
	}
}

void DCLL::delatend()
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
	else
	{
		rear = rear->prev;
		front->prev = rear;
		delete rear->next;		//Note - try with extra pointer
		rear->next = front;
	}
}

void DCLL::addbypos(int pos,int x)
{
	int n;
	n = count();
	//check valid position
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
		q->prev = p;
		q->next->prev = q;
		if(q->next == front)	//OR if(pos == n+1) OR if(p == rear)
		{
			rear = q;
		}
	}
}

void DCLL::delbypos(int pos)
{
	int n;
	n = count();
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
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;	//q will refer to node to be deleted
		p->next = q->next;
		p->next->prev = p;	//OR q->next->prev = p;
		if(q == rear)	//OR if(pos == n)
		{
			rear = p;
		}
		delete q;		//delete q in last
	}
}

void DCLL::makeEmpty()
{
	Node * p = front;
	do
	{
		p = front;
		front = front->next;
		front->prev = rear;
		rear->next = front;
		delete p;
		//cout<<"\n-"; 
	}while(p != front);
	front = rear = NULL;
}

int main()
{
	DCLL L;
	int pos,x,ch;
	
	do
	{
		cout<<"\n\n__________MENUE__________";
		cout<<"\n1.  create list";
		cout<<"\n2.  show list";
		cout<<"\n3.  reverse show list";
		cout<<"\n4.  count nodes";
		cout<<"\n5.  search data";
		cout<<"\n6.  add at beg";
		cout<<"\n7.  add at end";
		cout<<"\n8.  add by pos";
		cout<<"\n9.  del at beg";
		cout<<"\n10. del at end";
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
				cout<<"\nList in forward order :\n";
				L.show();
				break;
				
			case 3:
				cout<<"\nList in reverse order :\n";
				L.rev_show();
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
