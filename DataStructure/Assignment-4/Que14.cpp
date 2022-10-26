// Q 14]. 

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;


int leap_year(int year)			//return 1 if leap year else returns 0
{
	if(((year/4)%2) == 0)			//if year is evenly divisible by 4, go inner step
	{
		if(((year/100)%2) == 0)		//if year is evenly divisible by 100, go inner step
		{
			if(((year/400)%2) == 0)	//if year is evenly divisible by 400, then it is leap year (366 days)
			{
				//leap year
				return 1;	//if year is evenly divisible by 400,then it is leap year.
			}
			else			//if year is not evenly divisible by 400, then it is not a leap year(365 days)
			{
				//Not leap year
				return 0;
			}
		}
		else				//if year is not evenly divisible by 100, then it is leap year (366 days)
		{
			//leap year
			return 1;
		}
	}
	else					//if year is not evenly divisible by 4 then it is not a leap year (365 days)
	{
		//Not leap year
		return 0;
	}
}

class Month
{
	public:
		char month[15];
		int no_of_days;
		
		Month()
		{
			strcpy(month,"None");
			no_of_days = 0;
		}
		void getdata()
		{
			cout<<"\nEnter month name : ";
			cin.getline(month,13,'\n');
			set_days(month);
			/*cout<<"\nEnter number of days : ";
			cin>>no_of_days; */
		}
		void showdata()
		{
			cout<<"\nMonth = "<<setw(10)<<month<<"\t\tNo of days = "<<no_of_days;
		}
		void set_days(char * p);
};

void Month::set_days(char * p)
{
	int yr;
	/*cout<<"\nEnter year : ";
	cin>>yr; */
	yr = 2021;
	
	if(strcmp("January",p)==0 || strcmp("March",p)==0 || strcmp("May",p)==0 || strcmp("July",p)==0 ||
	   strcmp("August",p)==0 || strcmp("October",p)==0 || strcmp("December",p)==0)
	{
		no_of_days = 31;
	}
	
	else if(strcmp("April",p)==0 || strcmp("June",p)==0 || strcmp("September",p)==0 || strcmp("November",p)==0)
	{
		no_of_days = 30;
	}
	
	else if(strcmp("February",p) == 0)
	{
		if(leap_year(yr))
		{
			//it is leap year
			no_of_days = 29;
		}
		else	//not a leap year
		{
			no_of_days = 28;
		}
	}
	
	else
	{
		cout<<"\nInvalid Month";
	}
}

class Node
{
	public:
		Month data;
		Node * next;
		
		Node()
		{
			data.getdata();
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
		void show_30_day();
		void show_31_day();
		void show_char();
};

void SLL::create()
{
	if(head != NULL)
	{
		cout<<"\nList Already Created...";
		return;
	}
	
	int n;
	cout<<"\nHow many months list ? ";
	cin>>n;
	cin.ignore(1);
	if(n<1 || n>12)
	{
		cout<<"\nInvalid number of months";
		return;
	}
	head = new Node();
	Node * p = head;
	
	for(int i=1; i<=n-1; i++)
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
	cout<<"\nMonths List : ";
	Node * p = head;
	while(p != NULL)
	{
		p->data.showdata();
		p = p->next;
	}
}

void SLL::show_30_day()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	cout<<"\nMonths with number of days 30 : ";
	Node * p = head;
	while(p != NULL)
	{
		if(p->data.no_of_days == 30)
		{
			p->data.showdata();	
		}
		p = p->next;
	}	
}

void SLL::show_31_day()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	cout<<"\nMonths with number of days 31 : ";
	Node * p = head;
	while(p != NULL)
	{
		if(p->data.no_of_days == 31)
		{
			p->data.showdata();	
		}
		p = p->next;
	}	
}

void SLL::show_char()
{
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	char ch;
	cout<<"\nEnter character : ";
	cin>>ch;
	Node * p = head;
	while(p != NULL)
	{
		if(ch == p->data.month[0])		//comparing 1st character of string with ch variable
		{
			p->data.showdata();
		}
		p = p->next;
	}
}

int main()
{
	SLL L;
	
	/*L.create();
	L.show();
	L.show_30_day();
	L.show_31_day();
	L.show_char();*/
	
	int ch;
	do
	{
		cout<<"\n\n_______________MENUE_______________";
		cout<<"\n1. Create List of Months";
		cout<<"\n2. Show List of Months";
		cout<<"\n3. Show Months with 30 days";
		cout<<"\n4. Show Months with 31 days";
		cout<<"\n5. show Months with character";
		cout<<"\n6. exit";
		cout<<"\n___________________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				L.create();
				break;
				
			case 2:
				L.show();
				break;
			
			case 3:
				L.show_30_day();
				break;
				
			case 4:
				L.show_31_day();
				break;
				
			case 5:
				L.show_char();
				break;
				
			case 6:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 6);
	
	return 0;
}


