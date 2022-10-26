// Q 5] Usind concept of composition

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Student
{
	public:
		char name[30];
		int age;
		int no_of_matches;
};

class Node
{
	public:
		Student data;		//composition
		Node * next;
		
		Node()
		{
			cout<<"\nEnter Name : ";
			cin.getline(data.name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>data.age;
			cout<<"\nEnter No of matches played : ";
			cin>>data.no_of_matches;
			cin.ignore(1);
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

		void create_team();
		void show_team();
		void show_captain();
		void show_vice_cap();
		void max_matches();		// will print details of player who played max_matches
		void min_matches();		// will print details of played who played min_matches
		void senior_age();		// will print details of senior player in team
		void younger_age();		// will print details of younger player in team
		void sort();
};

void SLL::create_team()
{
	if(head != NULL)
	{
		cout<<"\nTeam Already Created";
		return;
	}
	
	cout<<"\nCreate PICT Cricket Team\n";
	int x,i;
	Node * p;
	cout<<"\nEnter details of Captain\n";
	head = new Node();
	
	p = head;
	cout<<"\nEnter details of remaining teammates\n";
	for(i=1; i<=9; i++)
	{
		cout<<"\nPlayer "<<i<<" : ";
		p->next = new Node();
		p = p->next;
	}
	
	cout<<"\nEnter datails of Vice Captain\n";
	p->next = new Node();
	p = p->next;
}

void SLL::show_team()
{
	if(head == NULL)
	{
		cout<<"\nTeam Not Created";
		return;
	}
	cout<<"\n-------------------------------PICT Cricket Team-------------------------------\n";
	
	Node * p = head;
	//captain
	cout<<"\nName = "<<p->data.name<<"\t\tAge = "<<p->data.age<<"\tNo of matches played = "<<p->data.no_of_matches;
	cout<<"\t\t-Captain";
	p = p->next;
	
	//players
	while(p->next != NULL)
	{
		cout<<"\nName = "<<p->data.name<<"\t\tAge = "<<p->data.age<<"\tNo of matches played = "<<p->data.no_of_matches;
		cout<<"\t\t-Player";
		p = p->next;
	}
	
	//Vice captain
	cout<<"\nName = "<<p->data.name<<"\t\tAge = "<<p->data.age<<"\tNo of matches played = "<<p->data.no_of_matches;
	cout<<"\t\t-Vice Captain";
	
	cout<<"\n---------------------------------------------------------------------------------";
}

void SLL::show_captain()
{
	cout<<"\nDetails of Captain : ";
	cout<<"\nName = "<<head->data.name<<"\t\tAge = "<<head->data.age<<"\tNo of matches played = "
		<<head->data.no_of_matches;
}

void SLL::show_vice_cap()
{
	cout<<"\nDetails of Vice Captain : ";
	Node * p = head;
	while(p->next != NULL)
	{
		p = p->next;	// p will refer to last node which is VC
	}
	cout<<"\nName = "<<p->data.name<<"\t\tAge = "<<p->data.age<<"\tNo of matches played = "<<p->data.no_of_matches;	
}

void SLL::max_matches()
{
	Node * p = head;
	Node * q;
	int max = p->data.no_of_matches;	//initialized to first player's no of matches
	while(p != NULL)
	{
		if(max <= p->data.no_of_matches)
		{
			max = p->data.no_of_matches;
			q = p;
		}
		p = p->next;
	}
	cout<<"\nPlayer who played maximum matches is : ";
	cout<<"\nName = "<<q->data.name<<"\t\tAge = "<<q->data.age<<"\tNo of matches played = "<<q->data.no_of_matches;
}

void SLL::min_matches()
{
	Node * p = head;
	Node * q;
	int min = p->data.no_of_matches;	//initialized to first player's no of matches
	while(p != NULL)
	{
		if(min >= p->data.no_of_matches)
		{
			min = p->data.no_of_matches;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nPlayer who played minimum matches is : ";
	cout<<"\nName = "<<q->data.name<<"\t\tAge = "<<q->data.age<<"\tNo of matches played = "<<q->data.no_of_matches;
}

void SLL::senior_age()
{
	Node * p = head;
	Node * q;
	int senior = p->data.age;	//initialized to first player's age
	while(p != NULL)
	{
		if(senior <= p->data.age)
		{
			senior = p->data.age;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nSenior Player by age is : ";
	cout<<"\nName = "<<q->data.name<<"\t\tAge = "<<q->data.age<<"\tNo of matches played = "<<q->data.no_of_matches;
}

void SLL::younger_age()
{
	Node * p = head;
	Node * q;
	int younger = p->data.age;	//initialized to first player's age
	while(p != NULL)
	{
		if(younger >= p->data.age)
		{
			younger = p->data.age;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nYounger Player by age is : ";
	cout<<"\nName = "<<q->data.name<<"\t\tAge = "<<q->data.age<<"\tNo of matches played = "<<q->data.no_of_matches;
}

void SLL::sort()
{	
	int ch;
	cout<<"\n________________SORT________________";
	cout<<"\n1. Sort by age";
	cout<<"\n2. sort by no of matches played";
	cout<<"\n____________________________________";
	cout<<"\nEnter choice of sorting : ";
	cin>>ch;
	
	Node * p = head->next;		//to avoid swapping of captain
	Node * q;
	Student temp;
	
	if(ch == 1)
	{
		while(p->next != NULL)
		{
			q = p->next;
			while(q->next != NULL)		//To avoid swapping of vice captain
			{
				if(p->data.age > q->data.age)
				{
					//swapping of Student object
					temp    = p->data;
					p->data = q->data;
					q->data = temp;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	if(ch == 2)
	{
		while(p->next != NULL)
		{
			q = p->next;
			while(q->next != NULL)		//To avoid swapping of vice captain
			{
				if(p->data.no_of_matches > q->data.no_of_matches)
				{
					//swapping of Student object
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
	SLL T;
	//T.create_team();
	//T.show_team();
	//T.show_captain();
	//T.show_vice_cap();
	//T.max_matches();
	//T.min_matches();
	//T.senior_age();
	//T.younger_age();
	//T.sort();
	//T.show_team();
	//T.sort();
	//T.show_team();
	
	int ch;
	do
	{
		cout<<"\n\n______________________MENUE______________________";
		cout<<"\n1.  Create Team";
		cout<<"\n2.  Details of Team";
		cout<<"\n3.  Details of Captain";
		cout<<"\n4.  Details of Vice Captain";
		cout<<"\n5.  Player who played max mathches";
		cout<<"\n6.  Player who played min matches";
		cout<<"\n7.  Senior player by age";
		cout<<"\n8.  Younger player by age";
		cout<<"\n9.  Sort players except Capt. & VCapt.";
		cout<<"\n10. Exit";
		cout<<"\n_________________________________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cin.ignore(1);
				T.create_team();
				break;
				
			case 2:
				T.show_team();
				break;
				
			case 3:
				T.show_captain();
				break;
				
			case 4:
				T.show_vice_cap();
				break;
				
			case 5:
				T.max_matches();
				break;
				
			case 6:
				T.min_matches();
				break;
				
			case 7:
				T.senior_age();
				break;
				
			case 8:
				T.younger_age();
				break;
				
			case 9:
				T.sort();
				break;
				
			case 10:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 10);
	
	return 0;
}

