// Q 17]. Pinnacle Club (Using SLL)

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Student
{
	public:
		char name[30];
		char prn[20];
		Student * next;
		
		Student()
		{
			cout<<"\nEnter name of student : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter PRN of student  : ";
			cin.getline(prn,18,'\n');
			//cin.ignore();
			next = NULL;
		}
};

class Pinnacle
{
		Student * president;
		Student * secretary;
		
	public:
		Pinnacle()
		{
			president = NULL;
			secretary = NULL;
		}
		
		int count();
		void show();
		void addatbeg();
		void addatend();
		void Add();
		void delatbeg();
		void delatend();
		void Delete();
};

int Pinnacle::count()
{
	Student * p = president;
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

void Pinnacle::show()
{
	if(president == NULL)
	{
		cout<<"\nPinnacle Club has no any members";
		return;
	}
	cout<<"\n\n--------------------------------Pinnacle Club--------------------------------\n";
	Student * p = president;
	while(p != NULL)
	{
		if(p == president)
		{
			cout<<"\nName = "<<p->name<<"\t\tPRN = "<<p->prn;
			cout<<"\t\t-President";
		}
		else if(p == secretary)
		{
			cout<<"\nName = "<<p->name<<"\t\tPRN = "<<p->prn;
			cout<<"\t\t-Secretary";
		}
		else
		{
			cout<<"\nName = "<<p->name<<"\t\tPRN = "<<p->prn;
			cout<<"\t\t-Member";
		}
		p = p->next;
	}
	cout<<"\n---------------------------------------------------------------------------------";
}

void Pinnacle::addatbeg()				//for president
{
	if(president == NULL)
	{
		president = new Student();
	}
	else
	{
		Student * p;
		p = new Student();
		p->next = president;
		president = p;	
	}
}

void Pinnacle::addatend()				//for secretary
{
	if(president == NULL)
	{
		president = new Student();
	}
	else
	{
		Student * p = president;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Student();
		p = p->next;
		secretary = p;
	}
}

void Pinnacle::Add()
{
	int ch;
	cout<<"\n-----------------------";
	cout<<"\n1. Add President";
	cout<<"\n2. Add Secretary";
	cout<<"\n3. Add Member";
	cout<<"\n-----------------------";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	cin.ignore(1);
	
	if(ch==1)
	{
		if(president == NULL)
		{
			cout<<"\nEnter details of President";
			addatbeg();
		}
		else
		{
			char c;
			cout<<"\nPresident already exits for Club. Do you want to change President? (y/n) : ";
			cin>>c;
			if(c == 'y' || c=='Y')
			{
				char x;
				cout<<"\nDo you want to make previous president as member or remove his/her membership? ";
				cout<<"\n	[ y(make member)/ n(remove membership)] : ";
				cin>>x;
				cin.ignore(1);
				cout<<"\nEnter details of new President";
				if(x=='y' || x=='Y')
				{
					addatbeg();
				}
				else
				{
					delatbeg();		//To remove previous president
					addatbeg();		//To add new president
				}
			}
		}
	}
	else if(ch == 2)
	{
		if(president == NULL)
		{
			cout<<"\nCan't add Secretary... choose President first";
			return;
		}
		if(secretary == NULL)
		{
			cout<<"\nEnter details of secretary";
			addatend();
		}
		else
		{
			char c;
			cout<<"\nSecretary already exits for Club. Do you want to change Secretary? (y/n) : ";
			cin>>c;
			if(c == 'y' || c=='Y')
			{
				char x;
				cout<<"\nDo you want to make previous Secretary as member or remove his/her membership? ";
				cout<<"\n	[ y(make member)/ n(remove membership)] : ";
				cin>>x;
				cin.ignore(1);
				cout<<"\nEnter details of new Secretary";
				if(x=='y' || x=='Y')
				{
					addatend();
				}
				else
				{
					delatend();		//To remove previous secretary
					addatend();		//To add new secretary
				}
			}
		}
	}
	else if(ch == 3)
	{
		if(president==NULL || secretary==NULL)
		{
			cout<<"\nCan't add members... Choose President & Secretary first";
			return;
		}
		else
		{
			cout<<"\nEnter details of Member";
			Student * p = president;		//while adding members president & secretary should remain as it is
			Student * q;
			while(p->next != secretary)
			{
				p = p->next;
			}
			q = new Student();
			q->next = p->next;
			p->next = q;
		}
	}
}

void Pinnacle::delatbeg()					//for deleting president
{
	if(president == NULL)
	{
		cout<<"\nCan't delete... club has no members";
		return;
	}
	if(president->next == NULL)
	{
		delete president;
		president == NULL;
	}
	else
	{
		Student * p = president;
		president = president->next;
		delete p;
	}
}

void Pinnacle::delatend()					//for deleting secretary
{
	if(president == NULL)
	{
		cout<<"\nCan't delete... club has no members";
		return;
	}
	if(president->next == NULL)
	{
		delete president;
		president == NULL;
		secretary == NULL;
	}
	else
	{
		Student * p = president;
		Student * q;
		while(p->next != NULL)		//OR while(p != secretary)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		secretary = q;
		delete p;
	}
}

void Pinnacle::Delete()
{
	int ch;
	cout<<"\n-----------------------";
	cout<<"\n1. Remove President";
	cout<<"\n2. Remove Secretary";
	cout<<"\n3. Remove Member";
	cout<<"\n-----------------------";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	
	if(ch == 1)
	{
		delatbeg();				//remove president first
		char c;
		cout<<"\nDo you want to add new President or make next member as President ? (y/n) : ";
		cin>>c;
		cin.ignore(1);
		if(c=='y' || c=='Y')
		{
			cout<<"\nEnter details of new president";
			addatbeg();
		}
	}
	else if(ch == 2)
	{
		delatend();				//remove secretary first
		char c;
		cout<<"\nDo you want to add new Secretary or make previous member as Secretary ? (y/n) : ";
		cin>>c;
		cin.ignore(1);
		if(c=='y' || c=='Y')
		{
			cout<<"\nEnter details of new Secretary";
			addatend();
		}
	}
	else if(ch == 3)
	{
		if(president == NULL)
		{
			cout<<"\nCan't delete member... No members in club";
			return;
		}
		
		char roll[20];
		cout<<"\nEnter PRN of member to be removed : ";
		cin.ignore(1);
		cin.getline(roll,18,'\n');
		
		Student * p = president;
		Student * q;
		while(p != secretary)		//to avoid secretary
		{
			q = p;
			p = p->next;			//to avoid president 
			if(strcmp(roll,p->prn) == 0)
			{
				q->next = p->next;
				delete p;
				p = q;				//OR p = q->next; 				
			}
		}
	}
}


int main()
{
	Pinnacle P;
	int ch;
	
	do
	{
		cout<<"\n\n_____________MENUE_____________";
		cout<<"\n1. Add Members";
		cout<<"\n2. Delete Members";
		cout<<"\n3. Display Members";
		cout<<"\n4. Compute Total Tembers";
		cout<<"\n5. Exit";
		cout<<"\n_______________________________";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				P.Add();
				break;
				
			case 2:
				P.Delete();
				break;
				
			case 3:
				P.show();
				break;
				
			case 4:
				cout<<"\nTotal Members in Pinnacle Club (including president & secretary) = "<<P.count();
				break;
			
			case 5:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 5);
	
	return 0;
}



