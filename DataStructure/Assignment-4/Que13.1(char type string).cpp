// Q 13.1]. Create an SLL of weekdays. Scan a weekday from user & delete it. 
//	Using char type string.

#include<iostream>
#include<string.h>
using namespace std;

class Node
{
	public:
		char day[12];
		Node * next;
		
		Node()
		{
			cout<<"\nEnter weekday : ";
			//cin.getline(day,10,'\n');
			cin>>day;		//as day name is not space seperated 
			next = NULL;
		}
};

class SLL
{
		Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void show();
		void delbyday();
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Already Created...";
		return;
	}
	
	int n;
	cout<<"\nHow many days? ";
	cin>>n;
	if(n<1 || n>7)
	{
		cout<<"\nInvalid number of days";
		//create();
		return;
	}
	head = new Node();
	Node * p = head;
	for(int i=1; i<=n-1; i++)
	{
		p->next = new Node();
		p = p->next;
	}
	cout<<"\nList of weekdays created successfully";
}

void SLL::show()
{
	if(head == NULL)
	{
		cout<<"\nList Empty";
		return;
	}
	cout<<"\n\nList of Weekdays : ";
	Node * p = head;
	while(p != NULL)
	{
		cout<<"\n"<<p->day;
		p = p->next;
	}
}

void SLL::delbyday()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete ...empty list";
		return;
	}
	
	char str[12];
	cout<<"\n\nEnter weekday to be deleted : ";
	cin>>str;
	
	if(head->next == NULL)		//if list contains only one node
	{
		if((head->day,str) == 0)
		{
			delete head;
			head = NULL;
		}
	}
	else
	{
		Node * p;
		Node * q;
		
		while(strcmp(head->day,str) == 0)
		{
			p = head;
			head = head->next;
			delete p;
		}
		
		p = head;		//for new head if...
		while(p != NULL)	
		{
			q = p;
			p = p->next;
			if(p != NULL)
			{
				if(strcmp(p->day,str) == 0)
				{
					q->next = p->next;
					delete p;
					p = q;
				}
			}
		}	
	}
}

int main()
{
	SLL L;
	
	L.create();
	L.show();
	L.delbyday();
	L.show();
	L.delbyday();
	L.show();
	
	return 0;
}
