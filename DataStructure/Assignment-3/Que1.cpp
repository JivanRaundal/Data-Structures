// Q 1]. 

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
		void addafterelement(int x,int a);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
		void delafterelement(int x);
		void sort();
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
		cout<<"\nEnter next data or 'STOP' to stop : ";
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
	Node *p = head;
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
	int n = count();
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid Position";
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
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;
		}
		temp = new Node(x);
		temp->next = p->next;
		p->next = temp;
	}
}

void SLL::addafterelement(int x,int a)
{
	if(!search(x))	
	{
		cout<<"\nElement Not Found";
		return;
	}
	
	Node * p = head;
	Node * q = NULL;
	/*while(p->data != x)
	{
		p = p->next;
	}
	q = new Node(a);
	q->next = p->next;
	p->next = q;*/
	
	//OR
	while(p != NULL)
	{
		if(p->data == x)
		{
			break;
		}
		p = p->next;
	}
	q = new Node(a);
	q->next = p->next;
	p->next = q;
}

void SLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete...empty list";
		return;
	}
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
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
		cout<<"\nCan't delete...empty list";
		return;
	}
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
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
}

void SLL::delbypos(int pos)
{
	int n = count();
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
		Node * q = NULL;
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;		//p will refer to node previous of q i.e. node to be updated
		}
		q = p->next;	//q will refer to node to be deleted
		p->next = q->next;
		delete q;
	}
}

void SLL::delafterelement(int x)
{
	if(!search(x))
	{
		cout<<"\nElement Not Found";
		return;
	}
	
	Node * p = head;
	Node * q = NULL;
	while(p->data != x)
	{
		p = p->next;
	}
	q = p->next;
	if(q == NULL)
	{
		cout<<"\nNo element available to delete after an element "<<x<<".";
		return;
	}
	p->next = q->next;
	delete q;
	/*if(q != NULL)	//q will be NULL if x is last element & delete NULL will give error
	{
		delete q;
	}*/
}

void SLL::sort()
{
	int ch;
	cout<<"\n-----------------------------";
	cout<<"\n1. Sort in ascending order";
	cout<<"\n2. sort in descending order";
	cout<<"\n-----------------------------";
	cout<<"\nEnter choice of sorting : ";
	cin>>ch;
	
	if(ch == 1)	// ascending order
	{
		Node * p = head;
		Node * q = NULL;
		while(p != NULL)
		{
			q = p->next;
			while(q != NULL)
			{
				if(p->data > q->data)
				{
					int temp;
					temp    = p->data;
					p->data = q->data;
					q->data = temp;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	else	//ch = 2 i.e. descending order
	{
		Node * p = head;
		Node * q = NULL;
		while(p != NULL)
		{
			q = p->next;
			while(q != NULL)
			{
				if(p->data < q->data)
				{
					int temp;
					temp    = p->data;
					p->data = q->data;
					q->data = temp;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
}

int main()
{
	SLL L;
	int pos,x,a,ch;
	
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
		cout<<"\n8.  add after element";
		cout<<"\n9.  del at beginning";
		cout<<"\n10. del at end";
		cout<<"\n11. del by position";
		cout<<"\n12. del after element";
		cout<<"\n13. sort linked list";
		cout<<"\n14. exit";
		cout<<"\n_____________________________";
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
				cout<<"\nEnter data to add at beginning : ";
				cin>>x;
				L.addatbeg(x);
				break;
				
			case 6:
				cout<<"\nEnter data to add at end : ";
				cin>>x;
				L.addatend(x);
				break;
				
			case 7:
				cout<<"\nEnter poition and data to add : ";
				cin>>pos>>x;
				L.addbypos(pos,x);
				break;
				
			case 8:
				cout<<"\nEnter element to search & element to be added after the searched element : ";
				cin>>x>>a;
				L.addafterelement(x,a);
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
				cout<<"\nEnter element to search & delete element next to the searched element : ";
				cin>>x;
				L.delafterelement(x);
				break;
				
			case 13:
				L.sort();
				break;
				
			case 14:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...plz try again!!!";
		}
	}while(ch != 14);
	return 0;
}
