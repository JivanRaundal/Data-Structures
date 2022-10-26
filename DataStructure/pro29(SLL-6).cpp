// SLL using cpp

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
		void concat(SLL T);
};

void SLL::create()
{
	char str[10];
	cout<<"\nEnter first data or 'STOP' to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	head = new Node(atoi(str));
	
	while(1)
	{
		cout<<"\nEnter next data of 'STOP' to stop : ";
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		addatend(atoi(str));
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
		Node *p;
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
		while(p->next != NULL)	//p will refer to last node
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

void SLL::addbypos(int pos,int x)
{
	int n;
	n = count();	//count() will work for calling object of addbypos()
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid position";
		return;
	}
	cout<<"\nValid Position";
	if(pos == 1)
	{
		addatbeg(x);
	}
	else
	{
		Node * p = head;
		Node * temp = NULL;
		
		for(int i=1; i<(pos-1); i++)	//p will refer to node at pos-1
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
		cout<<"\nCan't delete ...empty list";
		return;
	}
	
	if(head->next == NULL)	// list contains only 1 node
	{
		delete head;
		head = NULL;
	}
	else		//list contains more than 1 node
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
		cout<<"\nCan't delete ...empty list";
		return;
	}
	
	if(head->next == NULL)	// list contains only 1 node
	{
		delete head;
		head = NULL;
	}
	else	//list contains more than 1 node
	{
		Node * p = head;
		Node * q = NULL;
		while(p->next != NULL)	//p will point to last node i.e. node to be deleted
		{
			q = p;				//q will point to last-second node i.e. node to be updated after deleting last node
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}

void SLL::delbypos(int pos)
{
	int n = count();
	//check pos is valid or not
	if(pos < 1 || pos > n)
	{
		cout<<"\nInvalid position";
		return;
	}
	
	if(pos == 1)
	{
		delatbeg();
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		for(int i=1; i<pos-1; i++)	// p will refer to pos-1 node i.e. node to be updated
		{
			p = p->next;
		}
		q = p->next;			//q will refer to the node to be deleted i.e. at pos th node
		p->next = q->next;
		delete q;
	}
}

void SLL::concat(SLL T)
{
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = T.head;
}

int main()
{
	SLL L1,L2;
	
	int x,pos,ch;
	
	do
	{
		cout<<"\n\n____________MENUE____________";
		cout<<"\n1.  create list";
		cout<<"\n2.  show list";
		cout<<"\n3.  count nodes";
		cout<<"\n4.  search data";
		cout<<"\n5.  add at beginning";
		cout<<"\n6.  add at end";
		cout<<"\n7.  add by position";
		cout<<"\n8.  del at beginning";
		cout<<"\n9.  del at end";
		cout<<"\n10. del by position";
		cout<<"\n11. concatenate lists";
		cout<<"\n12. exit";
		cout<<"\n_____________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				L1.create();
				break;
				
			case 2:
				cout<<"\nLIST :\n";
				L1.show();
				break;
				
			case 3:
				cout<<"\nTotal Nodes = "<<L1.count();
				break;
				
			case 4:
				cout<<"\nEnter data to be searched : ";
				cin>>x;
				if(L1.search(x))
				{
					cout<<"\nData Found";
				}
				else
				{
					cout<<"\nData Not Found";
				}
				break;
				
			case 5:
				cout<<"\nEnter data to add at beginning : ";
				cin>>x;
				L1.addatbeg(x);
				break;
				
			case 6:
				cout<<"\nEnter data to add at end : ";
				cin>>x;
				L1.addatend(x);
				break;
				
			case 7:
				cout<<"\nEnter position & data : ";
				cin>>pos>>x;
				L1.addbypos(pos,x);
				break;
				
			case 8:
				L1.delatbeg();
				break;
				
			case 9:
				L1.delatend();
				break;
				
			case 10:
				cout<<"\nEnter position of data to be deleted : ";
				cin>>pos;
				L1.delbypos(pos);
				break;
				
			case 11:
				cout<<"\nCreate another List to concatenate";
				L2.create();
				cout<<"\nList 2 :\n";
				L2.show();
				L1.concat(L2);	//List 2 will be concatenated with List 1
				break;
				
			case 12:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 12);
	return 0;
}
