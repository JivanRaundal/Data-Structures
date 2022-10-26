// CLL

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		
		Node()
		{
			data =0;
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
			front = NULL;
			rear  = NULL;
		}
		
		void create();
		void show();
		int count();
		int search(int x);
		void addatbeg(int x);
		void addbypos(int pos,int x);
		void addatend(int x);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
};

void CLL::create()
{
	if(front != NULL)
	{
		cout<<"\nList Already created...";
		return;
	}
	
	Node * p = NULL;
	int n,x,i;
	cout<<"\nHow many Nodes : ";
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
	rear = front;
	
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next data : ";
		cin>>x;
		
		rear->next = new Node(x);
		rear = rear->next;
		rear->next = front;
	}
	cout<<"\nCreated Successfully";
}

void CLL::show()
{
	if(front == NULL)
	{
		cout<<"\nList Empty";
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
		cout<<"\nEmpty List Can't search";
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
		Node * p;
		p = new Node(x);
		p->next = front;
		rear->next = p;
		front = p;
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
		
		if(pos == n+1)	//if pos == n+1, then only we have to change rear
		{
			rear = q;
		}
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

void CLL::delatbeg()
{
	 if(front == NULL)
	 {
	 	cout<<"\nCan't delete ...Empty List";
	 	return;
	 }
	 if(front == rear)	//i.e. if list contains only one node
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
		cout<<"\nCan't delete ...Empty List";
		return;
	}
	if(front == rear)	//i.e. if list contains only one node
	{
		delete front;
		front = rear = NULL;
	}
	else
	{
		Node * p = front;
		Node * q;
		while(p->next != front)		//OR while(p != rear)
		{
			q = p;			//q will refer to last 2nd node i.e. node to be updated
			p = p->next;	//p will refer to the last node. i.e. node to be deleted
		}
		rear = q;
		rear->next = front;
		delete p;
	}
}

void CLL::delbypos(int pos)
{
	int n = count();
	//check valid popsition
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
		delete q;
		
		if(pos == n)	//if pos == n, then only rear will change
		{
			rear = p;
		}
	}
}

int main()
{
	CLL L;
	
	int ch,pos,x;
	do
	{
		cout<<"\n\n------------------------";
		cout<<"\n1.  create CLL";
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
		cout<<"\n------------------------";
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
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 11);
	return 0;
}
