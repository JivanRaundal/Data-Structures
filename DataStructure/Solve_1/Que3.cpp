// Q 3].

#include<iostream>
using namespace std;

class Student
{
	public:
		char * name;
		int age;
		Student * next;
		
		Student()
		{
			cin.ignore(1);
			name = new char[20];
			cout<<"\nEnter Name : ";
			cin.getline(name,18,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
			
			next = NULL;
		}
		~Student()
		{
			cout<<"\n-";	//To confirm that destructor is called or not
			delete[] name;
		}
};

class SLL
{
		Student * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void show();
		void makeEmpty();
		
		friend void rec_rev_show(SLL T);
};

void SLL::create()
{
	Student * p = NULL;
	int n,i;
	cout<<"\nHow many Students? ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid Number";
		return;
	}
	
	head = new Student();
	
	p = head;
	for(i=1; i<=n-1; i++)
	{
		p->next = new Student();
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
	Student * p = head;
	while(p != NULL)
	{
		cout<<"\nName = "<<p->name<<"\t\tAge = "<<p->age;
		p = p->next;
	}
}

void rec_rev_show(SLL T)
{
	if(T.head == NULL)
	{
		return;
	}
	
	Student *p = T.head;
	T.head = T.head->next;
	rec_rev_show(T);
	cout<<"\nName = "<<p->name<<"\t\tAge = "<<p->age;
}

void SLL::makeEmpty()
{
	Student *p = NULL;;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

int main()
{
	SLL S;
	
	S.create();
	
	cout<<"\n\nStudent's List in forward order :";
	S.show();
	
	cout<<"\n\nStudent's List in reverse order :";
	rec_rev_show(S);
	
	S.makeEmpty();
	
	cout<<"\n\nStudent's List :";
	S.show();
	
	return 0;	
}
