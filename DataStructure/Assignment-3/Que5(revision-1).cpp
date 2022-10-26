// Assgn-3]. Q-5(PICT cricket team) 

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		char * name;
		int age;
		int matches;
		
		Student()
		{
			age = 0;
			matches = 0;
		}
		void getdata()
		{
			name = new char[30];
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
			cout<<"\nEnter total number of matches played : ";
			cin>>matches;
			cin.ignore(1);
		}
		/*void showdata()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<"\tNo of matches played = "<<matches;
		} */
};

class Node
{
	public:
		Student data;	//composition
		Node * next;
		
		Node()
		{
			data.getdata();
			next = NULL;
		}
};

class SLL
{
	private:
		Node * head;
		//Node * end;
		
	public:
		SLL()
		{
			head = NULL;
			//end = NULL;
		}
		
		void create_team();
		void show_team();
};

void SLL::create_team()
{
	if(head != NULL)
	{
		cout<<"\nTeam already created";
		return;
	}
	
	cout<<"\nCreating PICT cicket team\n";
	Node * p = NULL;
	cout<<"\nEnter details for captain";
	head = new Node();
	p = head;
	cout<<"\nEnter details of teammates";
	for(int i=1; i<=3; i++)
	{
		p->next = new Node();
		p = p->next;
	}
	cout<<"\nEnter details of vice captain";
	p->next = new Node();
	
	cout<<"\nTeam Created Successfully";
}

void SLL::show_team()
{
	if(head == NULL)
	{
		cout<<"\nTeam not created";
		return;
	}
	
	cout<<"\n\n----------------------------------PICT CRICKET TEAM----------------------------------";
	Node * p = head;
	cout<<"\nName = "<<p->data.name<<"\t\tAge : "<<p->data.age<<"\tNo of matches played = "<<p->data.matches;
	cout<<"\t-Captain";
	p = p->next;
	
	while(p->next != NULL)	//p will stop at last node
	{
		cout<<"\nName = "<<p->data.name<<"\t\tAge = "<<p->data.age<<"\tNo of matches played = "<<p->data.matches
			<<"t\t-Player";
		p = p->next;
	}
	
	cout<<"\nName = "<<p->data.name<<"\t\tAge : "<<p->data.age<<"\tNo of matches played = "<<p->data.matches;
	cout<<"\t-Vice Captain";
		
	cout<<"\n---------------------------------------------------------------------------------------";
}

int main()
{
	SLL T;
	T.create_team();
	T.show_team();
	return 0;
}
