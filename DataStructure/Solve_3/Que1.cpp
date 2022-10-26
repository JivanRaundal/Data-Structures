// Q 1].

#include<iostream>
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

class DLL
{
		Node * head;
	
	public:
		DLL()
		{
			head = NULL;
		}
		
		void addatbeg(int x);
		void addatend(int x);
		void delatbeg();
		void delatend();
		void show();
		void show_rev();
		void makeEmpty();
};

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
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Node(x);
		p->next->prev = p;
	}
}

void DLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete, ...List Empty";
		return;
	}
	if(head->next == NULL)		//list contains only one element
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
		cout<<"\nCan't delete ...Empty List";
		return;
	}
	if(head->next == NULL)		//list contains only one node
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->prev->next = NULL;
		delete p;
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
	while(p != NULL)	//OR while(p)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

void DLL::show_rev()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	while(p != NULL)	//OR while(p)
	{
		cout<<" "<<p->data;
		p = p->prev;
	}
}

void DLL::makeEmpty()
{
	Node * p = head;
	while(head != NULL)		//OR while(head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

int main()
{
	DLL L;
	
	/*L.addatbeg(10);
	L.addatbeg(20);
	L.addatend(30);
	cout<<"\n";
	L.show();
	cout<<"\n";
	L.show_rev();
	L.delatbeg();
	L.delatend();
	cout<<"\n";
	L.show();
	*/
	
	int x,ch;
	do
	{
		cout<<"\n\n------------------------";
		cout<<"\n1. add at beg";
		cout<<"\n2. add at end";
		cout<<"\n3. del at beg";
		cout<<"\n4. del at end";
		cout<<"\n5. show forward";
		cout<<"\n6. show reverse";
		cout<<"\n7. make list empty";
		cout<<"\n8. exit";
		cout<<"\n------------------------";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter data to add at beg : ";
				cin>>x;
				L.addatbeg(x);
				break;
				
			case 2:
				cout<<"\nEnter data to add at end : ";
				cin>>x;
				L.addatend(x);
				break;
				
			case 3:
				L.delatbeg();
				break;
				
			case 4:
				L.delatend();
				break;
				
			case 5:
				cout<<"\nList In forward order :\n";
				L.show();
				break;
				
			case 6:
				cout<<"\nList in reverse order :\n";
				L.show_rev();
				break;
				
			case 7:
				L.makeEmpty();
				break;
				
			case 8:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 8);
	return 0;
}
