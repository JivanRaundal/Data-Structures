// Q 13]. SLL

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
		int search(int x);
		void addatbeg(int x);
		void addatend(int x);
		void addbypos(int pos,int x);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nCan't create ...List already exist";
		return;
	}
	
	Node * p = NULL;
	int n,x,i;
	n = count();
	cout<<"\nHow many Nodes? ";
	cin>>n;
	//check if number is valid or not
	if(n < 1)
	{
		cout<<"\nPlz enter valid number";
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
	Node * p = head;
	int i=0;
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
	if(head == NULL)
	{
		head = new Node(x);
	}
	else
	{
		Node * p;
		p = new Node(x);
		p->next = head;
		head = p;
	}
}

void SLL::addatend(int x)
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

void SLL::addbypos(int pos,int x)
{
	int n;
	n = count();
	//check if position is valid or not
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid Position";
		return;
	}
	cout<<"\nValid position";
	if(pos == 1)
	{
		addatbeg(x);
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

void SLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete empty list";
		return;
	}
	
	if(head->next == NULL)	//list contains single node
	{
		delete head;
		head = NULL;
	}
	else					//contains more than 1 node
	{
		Node * p = head;
		head = head->next;
		delete p;
	}
}

void SLL::delatend()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete empty list";
		return;
	}
	
	if(head->next == NULL)	//list contains single node
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		while(p->next != NULL)	//p will refer to last node
		{
			q = p;				//q will refer to second last node (i.e. previous node of P)
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}

void SLL::delbypos(int pos)
{
	int n;
	n = count();
	//check if position is valid or not
	if(pos < 1 || pos > n)
	{
		cout<<"\nInvalid Position";
		return;
	}
	
	if(pos == 1)
	{
		delatbeg();
	}
	else
	{
		Node * p =head;
		Node * q = NULL;
		for(int i=1; i<pos-1; i++)	//p will refer to node at (pos-1)th location (i.e. to prev node of required node)
		{
			p = p->next;
		}
		q = p->next;			//q will refer to node at pos i.e. to the node which is to be deleted
		p->next = q->next;
		delete q; 
	}
}

int main()
{
	SLL L;
	
	int ch,pos,x;
	
	do
	{
		cout<<"\n\n____________MENUE____________";
		cout<<"\n1.  create list";
		cout<<"\n2.  show list";
		cout<<"\n3.  count total nodes";
		cout<<"\n4.  search for data";
		cout<<"\n5.  add at beginning";
		cout<<"\n6.  add at end";
		cout<<"\n7.  add by position";
		cout<<"\n8.  delete at beginning";
		cout<<"\n9.  delete at end";
		cout<<"\n10. delete by position";
		cout<<"\n11. exit";
		cout<<"\n_____________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				L.create();
				break;
				
			case 2:
				cout<<"\nList :\n";
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
					cout<<"\nData found";
				}
				else
				{
					cout<<"\nData Not found";
				}
				break;
					
			case 5:
				cout<<"\nEnter data to add at beginnig : ";
				cin>>x;
				L.addatbeg(x);
				break;
				
			case 6:
				cout<<"\nEnter data to be add at end : ";
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
				cout<<"\nEnter positon of data to be deleted : ";
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
