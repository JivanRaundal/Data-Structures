#include<iostream>
#include<string.h>
using namespace std;
class Student
{
	public:		
		char name[30];
		int age;
		void getdata()
		{
			cout<<"\nEnter name of student\n";
			cin.getline(name,28);
			cout<<"\nEnter age of student";
			cin>>age;
			cin.ignore(1);
		}
		void showdata()
		{
			cout<<"\nName: "<<name<<"\tAge: "<<age;
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
	Node* head;
	public:
		void create();//(Scan here number of students from user)
		void show();
		void addatbeg();
		void addatend();
		void delatbeg();
		void delatend();
		void delbyname(char*);
};
void SLL::create()
{
	cout<<"\nenter how many student to store data: ";int n;cin>>n;
	cin.ignore(1);
	if(n==0)
	{
		return;
	}
	head = new Node();
	Node* p = head;
	int i;
	for(i=2;i<=n;i++)
	{
		p->next=new Node();
		p=p->next;
	}
}
void SLL::addatbeg()
{
	Node* p = new Node();
	p->next = head;
	head = p;
}
void SLL::addatend()
{
	if(head==NULL)
	{
		head = new Node();
		return;
	}
	Node* p =head;
	while(p->next)
	{
		p=p->next;
	}
	p->next=new Node();
	
}
void SLL::delatbeg()
{
	if(head==NULL)
	{
		cout<<"\ncan not delete list is empty!";
		return;
	}
	if(head->next==NULL)
	{
		delete head;
		head = NULL;
		return;
	}
	Node* p = head;
	head = head->next;
	delete p;
}
void SLL::delatend()
{
	if(head==NULL)
	{
		cout<<"\ncan not delete list is empty!";
		return;
	}
	if(head->next==NULL)
	{
		delete head;
		head= NULL;
		return;
	}
	Node* p = head;
	Node* q = NULL;
	while(p->next)
	{
		q=p;
		p=p->next;
	}
	q->next = NULL;
	delete p;
}
void SLL::delbyname(char* str)
{
	if(head==NULL)
	{
		cout<<"\nlist is empty: can not delete!";
		return;
	}
	if(head->next==NULL)
	{
		if(strcmp(head->S.name,str)==0)
		{
			this->delatbeg();
			return;
		}
	}
	if(strcmp(head->S.name,str)==0)
	{
		this->delatbeg();
		this->delbyname(str);
	}
	Node* p = head;
	Node* q = NULL;
	while(p->next)
	{
		q = p;
		p=p->next;
		if(strcmp(p->S.name,str)==0)
		{
			q->next= p->next;
			delete p;
			this->delbyname(str);
		}	
	}
	
}
void SLL::show()
{
	if(head==NULL)
	{
		cout<<"\nList is empty! ";
		return;
	}
	Node* p = head;
	while(p)
	{
		p->S.showdata();
		p=p->next;
	}
}
int main()
{
	SLL S;
	S.create();
	S.show();
	//S.addatbeg();
	//S.show();
	//S.addatend();
	//S.show();
	/*S.delatbeg();
	S.show();
	S.delatend();
	S.show();
	S.delatend();
	S.show();*/
	char str[30];cout<<"\nenter name to delete: ";cin.getline(str,29);
	S.delbyname(str);
	S.show();

	return 0;
}
