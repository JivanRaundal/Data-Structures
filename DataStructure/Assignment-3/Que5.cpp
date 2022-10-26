// Q 5] by swapping individual members except next

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Student
{
	public:
		char * name;	//OR char name[20];
		int age;
		int no_of_matches;
		Student * next;
		
		Student()
		{
			//allocating memory for name
			name = new char[30];
			//cin.ignore(1);
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
			cout<<"\nEnter number of matches played : ";
			cin>>no_of_matches;
			cin.ignore(1);
			next = NULL;
		}
		~Student()	//destructor
		{
			delete[] name;
		}
};

class SLL
{
		Student * head;		//Captain
		Student * end;		//Vice Captain
	public:
		SLL()
		{
			head = NULL;
			end = NULL;
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
	cout<<"\nEnter details of Captain\n";
	head = new Student();
	end = head;
	
	cout<<"\nEnter details of remaining teammates\n";
	for(i=1; i<=9; i++)
	{
		cout<<"\nPlayer "<<i<<" : ";
		end->next = new Student();
		end = end->next;
	}
	
	cout<<"\nEnter datails of Vice Captain\n";
	end->next = new Student();
	end = end->next;
}

void SLL::show_team()
{
	if(head == NULL)
	{
		cout<<"\nTeam Not Created";
		return;
	}
	cout<<"\n-------------------------------PICT Cricket Team-------------------------------\n";
	Student * p = head;
	while(p != NULL)
	{
		if(p == head)
		{
			cout<<"\nName = "<<p->name<<"\t\tAge = "<<p->age<<"\tNo of matches played = "<<p->no_of_matches;
			cout<<"\t\t-Captain";
		}
		else if(p == end)
		{
			cout<<"\nName = "<<p->name<<"\t\tAge = "<<p->age<<"\tNo of matches played = "<<p->no_of_matches;
			cout<<"\t\t-Vice Captain";
		}
		else
		{
			cout<<"\nName = "<<p->name<<"\t\tAge = "<<p->age<<"\tNo of matches played = "<<p->no_of_matches;
			cout<<"\t\t-Player";
		}
		p = p->next;
	}
	cout<<"\n---------------------------------------------------------------------------------";
}

void SLL::show_captain()
{
	cout<<"\nDetails of Captain : ";
	cout<<"\nName = "<<head->name<<"\t\tAge = "<<head->age<<"\tNo of matches played = "<<head->no_of_matches;
}

void SLL::show_vice_cap()
{
	cout<<"\nDetails of Vice Captain : ";
	cout<<"\nName = "<<end->name<<"\t\tAge = "<<end->age<<"\tNo of matches played = "<<end->no_of_matches;	
}

void SLL::max_matches()
{
	Student * p = head;
	Student * q = NULL;
	int max = p->no_of_matches;	//initialized to first player's no of matches
	while(p != NULL)
	{
		if(max <= p->no_of_matches)
		{
			max = p->no_of_matches;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nPlayer who played maximum matches is : ";
	cout<<"\nName = "<<q->name<<"\t\tAge = "<<q->age<<"\tNo of matches played = "<<q->no_of_matches;
}

void SLL::min_matches()
{
	Student * p = head;
	Student * q = NULL;
	int min = p->no_of_matches;	//initialized to first player's no of matches
	while(p != NULL)
	{
		if(min >= p->no_of_matches)
		{
			min = p->no_of_matches;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nPlayer who played minimum matches is : ";
	cout<<"\nName = "<<q->name<<"\t\tAge = "<<q->age<<"\tNo of matches played = "<<q->no_of_matches;
}

void SLL::senior_age()
{
	Student * p = head;
	Student * q = NULL;
	int senior = p->age;	//initialized to first player's age
	while(p != NULL)
	{
		if(senior <= p->age)
		{
			senior = p->age;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nSenior Player by age is : ";
	cout<<"\nName = "<<q->name<<"\t\tAge = "<<q->age<<"\tNo of matches played = "<<q->no_of_matches;
}

void SLL::younger_age()
{
	Student * p = head;
	Student * q = NULL;
	int younger = p->age;	//initialized to first player's age
	while(p != NULL)
	{
		if(younger >= p->age)
		{
			younger = p->age;
			q = p;	
		}
		p = p->next;
	}
	cout<<"\nYounger Player by age is : ";
	cout<<"\nName = "<<q->name<<"\t\tAge = "<<q->age<<"\tNo of matches played = "<<q->no_of_matches;
}

void swap(Student *p,Student *q);		//prototype

void SLL::sort()
{
	Student * p = head->next;	//To avoid captain's comparison
	Student * q = NULL;
	
	int ch;
	cout<<"\n________________SORT________________";
	cout<<"\n1. Sort by age";
	cout<<"\n2. sort by no of matches played";
	cout<<"\n____________________________________";
	cout<<"\nEnter choice of sorting : ";
	cin>>ch;
	
	if(ch == 1)
	{
		while(p->next != NULL)		
		{
			q = p->next;
			while(q->next != NULL)		//upto end bcz to avoid vice captain's comparison
			{
				if(p->age > q->age)
				{
					swap(p,q);
				}
				q = q->next;
			}
			p = p->next;	
		}
	}
	
	if(ch == 2)
	{
		while(p != end)		
		{
			q = p->next;
			while(q != end)		//upto end bcz to avoid vice captain's comparison
			{
				if(p->no_of_matches > q->no_of_matches)
				{
					swap(p,q);
				}
				q = q->next;
			}
			p = p->next;	
		}		
	}
}

void swap(Student *p,Student *q)
{
	char str[30];
	int age;
	int no_of_matches;
	
	//swapping names
	strcpy(str,p->name);
	strcpy(p->name,q->name);
	strcpy(q->name,str);
	//swapping ages
	age    = p->age;
	p->age = q->age;
	q->age = age;
	//swapping no of matches played
	no_of_matches    = p->no_of_matches;
	p->no_of_matches = q->no_of_matches;
	q->no_of_matches = no_of_matches;
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
