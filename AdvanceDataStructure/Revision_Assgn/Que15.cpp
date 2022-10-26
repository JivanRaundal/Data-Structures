// Q.15] DLL

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Student
{
	public:
		int roll;
		char name[30];
		void getdata()
		{
			cout<<"\nEnter Roll : ";
			cin>>roll;
			cin.ignore(1);
			cout<<"Enter Name : ";
			cin.getline(name,28,'\n');
		}
		void printdata()
		{
			cout<<"\nRoll No = "<<roll<<"\tName = "<<name;
		}
};

class Node
{
	public:
		Student data;
		Node * prev;
		Node * next;
		Node()
		{
			data.getdata();
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
		void show_rev();
		void addatbeg();
		void addatend();
		void delatbeg();
		void delatend();
		void searchbyroll(int roll);
		void searchbyname(char * name);
		void delbyroll(int roll);
		void delbyname(char * name);
};

void DLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList already created";
		return;
	}
	int n;
	cout<<"\nHow many students? ";
	cin>>n;
	if(n<0)
	{
		return;
	}
	head = new Node();
	Node * p = head;
	for(int i=1; i<=n-1; i++)
	{
		p->next = new Node();
		p->next->prev = p;
		p = p->next;
	}
}

void DLL::show()
{
	cout<<"\n\nLIST :\n";
	if(head == NULL)
	{
		cout<<"Empty List";
		return;
	}
	Node * p = head;
	while(p != NULL)
	{
		p->data.printdata();
		p = p->next;
	}
}

void DLL::show_rev()
{
	cout<<"\n\nReverese List :\n";
	if(head == NULL)
	{
		cout<<"Empty List";
		return;
	}
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	while(p != NULL)
	{
		p->data.printdata();
		p = p->prev;
	}
}

void DLL::addatbeg()
{
	cout<<"\n";
	if(head == NULL)
	{
		head = new Node();
	}
	else
	{
		Node * p = new Node();
		p->next = head;
		p->next->prev = p;			//OR head->prev = p;
		head = p;
	}
}

void DLL::addatend()
{
	cout<<"\n";
	if(head == NULL)
	{
		head = new Node();
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Node();
		p->next->prev = p;
		p = p->next;
	}
}

void DLL::delatbeg()
{
	if(head == NULL)
	{
		cout<<"\ncan't delete";
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
		head->prev = NULL;
		delete p;
	}
}

void DLL::delatend()
{
	if(head == NULL)
	{
		cout<<"\ncan't delete";
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
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}	
}

void DLL::searchbyroll(int roll)
{
	if(head == NULL)
	{
		cout<<"\n\nStudent Not Present";
		return;
	}
	Node * p = head;
	while(p != NULL)
	{
		if(p->data.roll == roll)
		{
			cout<<"\n\nStudent Present";
			p->data.printdata();
			return;
		}
		p = p->next;
	}
	cout<<"\n\nStudent Not Present";
}

void DLL::searchbyname(char * name)
{
	if(head == NULL)
	{
		cout<<"\n\nStudent Not Present";
		return;
	}
	Node * p = head;
	while(p != NULL)
	{
		if(strcmp(p->data.name, name) == 0)
		{
			cout<<"\n\nStudent Present";
			p->data.printdata();
			return;
		}
		p = p->next;
	}
	cout<<"\n\nStudent Not Present";
}

void DLL::delbyroll(int roll)
{
	if(head == NULL)
	{
		cout<<"\n\nStudent Not Present";
		return;
	}
	if(head->data.roll == roll)
	{
		this->delatbeg();
		cout<<"\n\nStudent deleted";
		return;
	}
	Node * p = head;
	Node * q = head;
	while(p != NULL)		
	{
		if(p->data.roll == roll)
		{
			q->next = p->next;
			if(q->next != NULL)
			{
				q->next->prev = q;
			}
			delete p;
			cout<<"\n\nStudent deleted";
			return;
		}
		q = p;
		p = p->next;
	}
	cout<<"\n\nStudent Not Present";
}

void DLL::delbyname(char * name)
{
	if(head == NULL)
	{
		cout<<"\n\nStudent Not Present";
		return;
	}
	if(strcmp(head->data.name, name) == 0)
	{
		this->delatbeg();
		cout<<"\n\nStudent deleted";
		return;
	}
	Node * p = head;
	Node * q = head;
	while(p != NULL)		
	{
		if(strcmp(p->data.name, name) == 0)
		{
			q->next = p->next;
			if(q->next != NULL)
			{
				q->next->prev = q;
			}
			delete p;
			cout<<"\n\nStudent deleted";
			return;
		}
		q = p;
		p = p->next;
	}
	cout<<"\n\nStudent Not Present";
}

int main()
{
	DLL L;
	L.create();
	L.show();
	L.show_rev();
	L.addatbeg();
	L.show();
	L.show_rev();
	L.addatend();
	L.show();
	L.show_rev();
	L.delatbeg();
	L.show();
	L.show_rev();
	L.delatend();
	L.show();
	L.show_rev();
	L.searchbyroll(102);
	L.searchbyroll(106);
	L.searchbyname("jivan");
	L.searchbyname("sakshi");
	/*
	L.delbyroll(102);
	L.show();
	L.show_rev();
	L.delbyroll(103);
	L.show();
	L.show_rev();
	*/
	L.delbyname("shahu");
	L.show();
	L.show_rev();
	L.delbyname("jivan");
	L.show();
	L.show_rev();
	
	return 0;
}
