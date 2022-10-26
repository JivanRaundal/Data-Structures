// DLL

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node
{
	public:
		int data;
		Node * prev;
		Node * next;
		
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

class DLL
{
	private:
		Node * head;
		
	public:
		DLL()
		{
			head = NULL;
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

void DLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Alredy Created...";
		return;
	}
	
	char str[10];
	cout<<"\nEnter first data or 'STOP' to stop : ";
	cin>>str;
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	head = new Node(atoi(str));
	
	Node * p = head;
	while(1)
	{
		cout<<"\nEnter next data or 'STOP' to stop : ";
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		//addatend(atoi(str));
		p->next = new Node(atoi(str));
		p->next->prev = p;
		p = p->next;
	}
}

void DLL::show()
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

void DLL::rev_show()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	Node * p = head;
	while(p->next != NULL)	//p will stop at last node
	{
		p = p->next;
	}
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->prev;
	}
}

int DLL::count()
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

int DLL::search(int x)
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

void DLL::addatbeg(int x)
{
	if(head == NULL)
	{
		head = new Node(x);
	}
	else
	{
		head->prev = new Node(x);
		head->prev->next = head;
		head = head->prev;
	}
}

void DLL::addatend(int x)
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
		p->next->prev = p;
	}
}

void DLL::addbypos(int pos,int x)
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
		Node * p = head;
		Node * q;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = new Node(x);
		q->next = p->next;
		p->next = q;
		q->prev = p;
		if(q->next != NULL)		//OR if(pos != n+1)
		{
			q->next->prev = q;
		}
	}
}

void DLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete ...empty list";
		return;
	}
	if(head->next == NULL)	//if list contains only one node
	{
		delete head;
		head = NULL;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}
}

void DLL::delatend()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete ...empty list";
		return;
	}
	if(head->next == NULL)		//if list contains only one node
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)		//p will refer to last node
		{
			p = p->next;
		}
		p->prev->next = NULL;
		delete p;
	}
}

void DLL::delbypos(int pos)
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
		Node * p = head;
		Node * q;
		for(int i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;	//q will refer to node to be deleted
		p->next = q->next;
		if(p->next != NULL)		//OR if(pos != n)
		{
			p->next->prev = p;		//OR q->next->prev = p;
		}
		delete q;
	}
}

/* OR delbypos() using p only
void DLL::delbypos(int pos)
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
		Node * p = head;
		for(int i=1; i<=pos-1; i++)  //bcz of p<=pos-1, p will refer to the node to be deleted
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if(p->next != NULL)		//OR if(pos != n)
		{
			p->next->prev = p->prev;		
		}
		delete q;
	}
}
*/

void DLL::makeEmpty()
{
	Node * p;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		if(head != NULL)
		{
			head->prev = NULL;
		}
		//cout<<"\n-";
		delete p;
	}
	cout<<"\nList is empty now";
}

int main()
{
	DLL L;
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
