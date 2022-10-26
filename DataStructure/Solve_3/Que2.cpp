// Q 2].

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Student
{
	public:
		char name[30];
		int age;
		
		Student()
		{
			strcmp(name,"None");
			age = 0;
		}
		void getdata()
		{
			cin.ignore(1);
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
		}
		void showdata()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<age;
		}
};

class Node
{
	public:
		Student S;
		Node * next;
		
		Node()
		{
			S.getdata();
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
		void addatbeg();
		void addatend();
		void delatbeg();
		void delatend();
		void delbyname(char * ptr);
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Already Created...";
		return;
	}
	int n,i;
	Node * p;
	cout<<"\nHow many nodes? : ";
	cin>>n;
	//cin.ignore(1);
	if(n<1)
	{
		cout<<"\nInvalid Number";
		return;	
	}
	head = new Node();
	
	p = head;
	for(i=1; i<=n-1; i++)
	{
		p->next = new Node();
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
	while(p != NULL)	//OR while(p)
	{
		p->S.showdata();
		p = p->next;
	}
}

void SLL::addatbeg()
{
	if(head == NULL)
	{
		head = new Node();
	}
	else
	{
		Node * p;
		p = new Node();
		p->next = head;
		head = p;
	}
}

void SLL::addatend()
{
	if(head == NULL)
	{
		head = new Node();
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)		//OR while(p->next)
		{
			p = p->next;
		}
		p->next = new Node();
	}
}

void SLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete ...empty list";
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
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node * p = head;
		Node * q;
		while(p->next)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}

void SLL::delbyname(char * ptr)
{
	if(head == NULL)
	{
		cout<<"\nList empty,..can't delete";
		return;
	}
	
	if(head->next == NULL)		//list contains only one node
	{
		if(strcmp(head->S.name,ptr) == 0)
		{
			delete head;
			head = NULL;
		}
	}
	else
	{
		while(strcmp(head->S.name,ptr) == 0)
		{
			delatbeg();
		}
		
		Node * p = head;
		Node * q = NULL;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
			if(strcmp(p->S.name,ptr) == 0)
			{
				q->next = p->next;
				delete p;
				p = q;		
			}
		}
	}
}

int main()
{
	SLL L;
	char str[30];
	int ch;
	
	do
	{
		cout<<"\n\n__________MENUE__________";
		cout<<"\n1. create list";
		cout<<"\n2. show list";
		cout<<"\n3. add at beg";
		cout<<"\n4. add at end";
		cout<<"\n5. del at beg";
		cout<<"\n6. del at end";
		cout<<"\n7. del by name";
		cout<<"\n8. exit";
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
				L.addatbeg();
				break;
				
			case 4:
				L.addatend();
				break;
				
			case 5:
				L.delatbeg();
				break;
				
			case 6:
				L.delatend();
				break;
				
			case 7:
				cin.ignore(1);
				cout<<"\nEnter Name to delete : ";
				cin.getline(str,28);
				L.delbyname(str);
				break;
				
			case 8:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 8);
	return 0;
}


